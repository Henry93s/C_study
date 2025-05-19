/*
	예외처리 방식
	1. if 문을 이용한 예외처리
	2. try catch throw 예외처리 메커니즘 사용
		- try ; 예외 발생 가능성 부분 검사
		- catch : 예외 처리 과정
		- throw : 예외 발생 알림
*/
#include <iostream>
using namespace std;

int main() {
	int a, b;
	int result;

	cout << "a/b 를 수행합니다. a b 를 입력하세요" << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	// 1. if 문을 이용한 예외처리
	if (b == 0) {
		cout << "0으로는 나눌 수 없습니다" << endl;
	}
	else {
		result = a / b;
		cout << "a/b의 결과는 " << result << "입니다" << endl;
	}

	cout << endl;
	cout << endl;

	// 2. try catch throw
	cout << "a/b 를 수행합니다. a b 를 입력하세요" << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	try { // try 코드 작성
		cin >> b;
		if (b == 0) { // 예외 발생 케이스 구분
			throw b; // 예외 발생 알림
		}
		result = a / b;
		cout << "a/b의 결과는 " << result << "입니다" << endl;
	}
	catch (int e) { // 예외 처리 코드
		cout << e << "으로는 나눌 수 없습니다." << endl;
	}

	cout << "종료" << endl;

	return 0;
}