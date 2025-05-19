/*
	C++20 부터 throw 대신 noexcept 함수 예외 선언을 사용함

	noexcept : throw 가 발생해도 catch 문으로 전달하지 않음
	noexcept(false) : throw 가 발생 시 catch 문으로 전달
*/
#include <iostream>
using namespace std;
void handler() {
	cout << "in handler" << endl;
}
void f1(void) noexcept(false) { // throw(int)
	cout << "about to throw 1" << endl;
	if (1) {
		throw 1;
	}
}
void f2(void) noexcept(false) { // throw(int) 
	try {
		f1();
	}
	catch (int e) {
		handler();
		throw; // noexcept 일 땐 throw 가 발생해도 밖 catch 문으로 전달되지 않음
	}
}

int main() {
	// f1(); // 에러 처리를 받을 catch 가 없으므로 프로그램 비정상 종료
	try {
		f2();
	}
	catch (int e) {
		cout << "caught exception from f2" << endl;
	}
}