#include <iostream>
using namespace std;

void Swap(int* x, int* y) { // 포인터에 의한 전달(매개변수 : 포인터 변수 !)
	// 포인터에 의한 전달
	int temp = *x; // 간접 참조 연산자 * 필요 !
	*x = *y;
	*y = temp;
}

void SwapRef(int& x, int& y) { // 레퍼런스에 의한 전달(매개변수 : 레퍼런스 변수 !)
	// 레퍼런스에 의한 전달
	int temp = x; // 간접 참조 연산자 불필요 !
	x = y;
	y = temp;
}

int main() {
	int a, b;
	// 포인터에 의한 인자 전달 과정
	cout << "두 수를 입력하세요: ";
	cin >> a >> b;
	cout << "포인터 매개변수 함수 Swap 호출 전의 a : " << a << " b : " << b << endl;
	Swap(&a, &b); // 주소를 인자로 전달함 !
	cout << "결과 a : " << a << " b : " << b << endl;

	// 레퍼런스에 의한 인자 전달 과정
	cout << "다시 두 수를 입력하세요: ";
	cin >> a >> b;
	cout << "레퍼런스 매개변수 함수 Swap 호출 전의 a : " << a << " b : " << b << endl;
	SwapRef(a, b); // 변수를 그대로 전달함 !
	cout << "결과 a : " << a << " b : " << b << endl;

	return 0;
}