#include <iostream>
using namespace std;

void print(int& x) {
	cout << "print (int& x)" << endl;
}
void print(const int& x) {
	cout << "print (const int& x)" << endl;
}

// r-value reference 
// : && 연산자를 통해 가능하며, 오직 r-value "임시 객체" 만을 참조하는 변수
void print(int&& x) {
// 메인 코드에서 print(3) 실행 시
// int&& x = 3; -> 다음 라인 넘어가면 3은 사라지는 r-value 임시 객체
// 따라서 x 는 r-value reference
	cout << "print (int&& x)" << endl;
}

int main() {
	const int& x = 3;
	print(x); // "print(const int& x)"
	print(3); // "print(int&& x)"

	return 0;
}