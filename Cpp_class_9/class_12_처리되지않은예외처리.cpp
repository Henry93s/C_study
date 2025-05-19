/*
*	기본적으로 C++ 에서 예외를 처리할 catch 절을 찾을 수 없을 때
*	미리 정의된 terminate() 함수를 호출 => "비정상" 종료
* 
	set_terminate() : terminate() 함수를 커스텀하여 미처리 예외를
		다룰 수 있음 => "정상" 종료
*/
#include <iostream>
#include <execution> // set_terminate 함수 정의에 필요
using namespace std;

void MyErrorHandler() {
	cout << "처리되지 않은 예외가 발생했습니다" << endl;
	exit(-1);
}

int main() {
	set_terminate(MyErrorHandler);
	try {
		throw 1;
	}
	catch (char* const ex) {
		// 이 catch 절은 위 throw 1 에서 반환하는 정수형 예외를 처리할 수 없음
	}
	return 0;
}