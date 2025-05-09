#include <iostream>
using namespace std;

char* NumberToStringPtr(int n) // 숫자를 문자열로 변경 함수(포인터 리턴)
// <-> 반대로 문자열을 숫자로 변경할 때는 atoi, atof 등 사용하면 됨.
/*
	포인터는 메모리에 동적할당으로 통해 생성된 주소이기 때문에 메모리 해제나 프로그램 종료 시
	까지 남아있는 heap 영역에 저장됨. 따라서 main 함수에까지 정상적으로 return 가능
*/
{
	char* p = new char[20];
	snprintf(p, 20, "%d", n);
	return p;
}
char* NumberToStringArr(int n) // 숫자를 문자열로 변경 함수(배열 리턴)
/*
	stack 에 저장되는 char arr[20] 이기 때문에 해당 함수에서만 사용되고 소멸됨
*/
{
	char arr[20];
	snprintf(arr, 20, "%d", n);
	return arr;
} 

int main() {
	int num;
	cout << "정수를 입력하세요: ";
	cin >> num;

	char* str = NumberToStringPtr(num);
	// char* str = NumberToStringArr(num);
	cout << "문자열로 변환된 값: " << str << endl;
	delete[] str;
	str = nullptr; // 가리키는 부분까지 지워주는 것이 좋음.

	return 0;
}