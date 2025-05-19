/*
	예외 객체 : 예외 발생을 알리는 객체
	예외 클래스 : 예외 객체의 생성을 위해 정의된 클래스
		- 객체를 통해서 예외를 알리면 정보를 더 자세히 전달할 수 있음
	- exception 클래스 : c++ 에서 제공하는 기초 예외 클래스
*/
#include <iostream>
using namespace std;
class MyException {
	int myValue;
public:
	MyException(int value) { // 사용자 정의 예외 클래스 생성자
		myValue = value;
	}
	void exceptionResult() { // 사용자 정의 예외 클래스 생성자를 통해 생성된
		// 객체의 멤버 변수 값에 따라 다른 에러 처리를 정의한 에러 처리 멤버 함수
		if (myValue < 10) {
			cout << "10 이상의 값을 입력하세요" << endl;
		}
		else if (myValue > 20) {
			cout << "20 이하의 값을 입력하세요" << endl;
		}
		else if (myValue % 7 != 0) {
			cout << "7의 배수를 입력하세요" << endl;
		}
	}
};

int main() {
	int value;
	try {
		cout << "10과 20 사이의 7의 배수를 입력하세요" << endl;
		cin >> value;
		if (value < 10 || value > 20 || value % 7 != 0) {
			throw MyException(value); // 사용자 정의 예외 클래스 객체로 에러 전달
		}
		cout << "정답!! 10과 20 사이의 7의 배수는 " << value << "입니다 !" << endl;
	}
	catch (MyException& e) {
		e.exceptionResult(); // 사용자 정의 예외 클래스에서 정의한 멤버 함수 호출
	}

	return 0;
}