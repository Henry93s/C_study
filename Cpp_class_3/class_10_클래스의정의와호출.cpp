#include <iostream>
using namespace std;

class Chulsoo { // class 정의
public: // 접근지정자 지정(public, 지정하지 않으면 default인 private)
	void Eat(); // class 멤버 함수 "선언"
}; // ; 주의(구조체, 공용체 포함)

void Chulsoo::Eat() { // Chulsoo:: 클래스 멤버 함수 정의
	cout << "철수는 먹는다" << endl;
}

int main(void) { // 함수에서 받을 인자가 아무것도 없는 것이 확실할 때는 void 표기하는 것이 좋음.
	// 단, void 로 작성하고 함수 인자가 발생하면 컴파일 에러 발생함.

	Chulsoo chulsoo; // 클래스 객체 "생성" (동작하는 실체)
	chulsoo.Eat();

	return 0;
}