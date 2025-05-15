#ifndef _ConTest_H2_
#define _ConTest_H2_
 #include<iostream>
using namespace std;

// 헤더 파일 : 기반 클래스 및 파생 클래스 선언 및 정의
class CON1 {
public:
	CON1(const int i);
	~CON1();
protected:
	int c; // 멤버 변수 추가
};

class CON2 : public CON1 {
public:
	CON2();
	~CON2();
};
#else
#endif
// class_7_상속관계에서의매개변수가있는생성자.cpp 에서 수정