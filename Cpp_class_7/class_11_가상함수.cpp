#include <iostream>
using namespace std;

class First {
public:
	virtual void MyFunc() {
		cout << "First Func" << endl;
	}
	virtual ~First() { cout << "~First" << endl; }
};

class Second : public First {
public:
	virtual void MyFunc() {
		cout << "Second Func" << endl;
	}
	virtual ~Second() { cout << "~Second" << endl; }
};

class Third : public Second {
public:
	void MyFunc() {
		cout << "Third Func" << endl;
	}
	virtual ~Third() { cout << "~Third" << endl; }
};

int main() {
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	/*
		가상 함수
		- 기반 클래스 포인터가 호출되더라도 파생 클래스 에 재정의된
			함수를 호출하도록 하는 기반 클래스의 멤버 함수
		- 가상 함수가 포인터 형일 때만 찾아갈 수 있음.
	*/

	/* 포인터 형에 상관 없이 포인터가 가리키는 객체의 마지막 오버라이딩
		함수를 호출 */
	fptr->MyFunc(); // third
	sptr->MyFunc(); // third
	tptr->MyFunc(); // third

	delete tptr; // ~Third, ~Second, ~First

	return 0;
}