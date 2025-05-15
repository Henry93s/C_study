#include "ConTest.h"

// 정의된 클래스들의 생성자, 소멸자 함수 재정의
CON1::CON1(const int i) {
	this->c = i;
	cout << "*** CON1 의 생성자 ***" << endl;
}

CON1::~CON1() {
	cout << "*** CON1 의 소멸자 ***" << endl;
}

// CON1 부모클래스 생성자에 디폴트 생성자가 없으므로(커스텀 생성자 정의)
//	부모클래스 생성자를 따로 이니셜라이저로 지정해야한다 
CON2::CON2():CON1(30) { // 원래는 :CON1() 처럼 디폴트 생성자로 부모 클래스 객체 생성
	cout << "*** CON2 의 생성자 ***" << endl;
}

CON2::~CON2() {
	cout << "*** CON2 의 소멸자 ***" << endl;
}
