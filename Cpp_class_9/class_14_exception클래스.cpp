/*
	what() : exception 클래스로부터 파생된 클래스 내에서 재정의 가능한
	가상 멤버 함수(return 문자열 포인터)
*/
#include <iostream>
using namespace std;
class MyException : public exception{
	int myValue;
public:
	MyException(int value) { // 사용자 정의 예외 클래스 생성자
		myValue = value;
	}
	virtual const char* what() const throw() { 
		if (myValue < 10) {
			return "10 이상의 값을 입력하세요";
		}
		else if (myValue > 20) {
			return "20 이하의 값을 입력하세요";
		}
		else if (myValue % 7 != 0) {
			return "7의 배수를 입력하세요";
		}
		else {
			return "잘못된 인수 전달";
		}
	}
};
// 예외 처리와 예외 데이터 전달이 여러 함수에 있어 걸쳐있을 때
// 마지막 예외를 전달받은 함수에서도 처리하지 않으면 terminate 함수발생 및 비정상 종료됨
// => 스택 풀기(stack unwinding) 처리 필요
int getMultiple() {
	int value;
	cout << "10과 20 사이의 7의 배수를 입력하세요" << endl;
	cin >> value;
	if (value < 10 || value > 20 || value % 7 != 0) {
		throw MyException(value); // 사용자 정의 예외 클래스 객체로 에러 전달
	}
	return value;
}
int getValue() {
	int value;
	value = getMultiple();
	return value;
}

int main() {
	int value;
	try {
		value = getValue();
		/*
		cout << "10과 20 사이의 7의 배수를 입력하세요" << endl;
		cin >> value;
		if (value < 10 || value > 20 || value % 7 != 0) {
			throw MyException(value); // 사용자 정의 예외 클래스 객체로 에러 전달
		}
		*/
		cout << "정답!! 10과 20 사이의 7의 배수는 " << value << "입니다 !" << endl;
	}
	catch (MyException& e) {
		// exception 클래스 내 정의된 what() 가상 함수에 따라서 return 된 문자열 출력
		cout << e.what() << endl; 
	}

	return 0;
}