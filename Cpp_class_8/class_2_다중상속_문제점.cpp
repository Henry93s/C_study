// 다이아몬드 형태의 다중 상속
#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "Person::Person() 생성자 호출" << endl;
	}
	~Person() {
		cout << "Person::~Person() 소멸자 호출" << endl;
	}
	// 순수 가상 함수
	// 상속 받은 자식 클래스에서 반드시 정의를 해줘야함!
	virtual void write() = 0;
};

class Chulsoo : public Person {
public:
	Chulsoo() : Person() {
		cout << "Chulsoo::Chulsoo() 생성자 호출" << endl;
	}
	~Chulsoo() {
		cout << "Chulsoo::~Chulsoo() 소멸자 호출" << endl;
	}
	// 순수 가상 함수
	// 상속 받은 자식 클래스에서 반드시 정의를 해줘야함!
	void write() {
		cout << "책을 잘 쓴다" << endl;
	}
};

class Younghee :public Person {
public:
	Younghee() : Person() {
		cout << "Younghee::Younghee() 생성자 호출" << endl;
	}
	~Younghee() {
		cout << "Younghee::~Younghee() 소멸자 호출" << endl;
	}
	// 순수 가상 함수
	// 상속 받은 자식 클래스에서 반드시 정의를 해줘야함!
	void write() {
		cout << "책을 못 쓴다" << endl;
	}
};

// 영철이 다중상속을 받으면서 다이아몬드 구조가 됨.
// => 부모 클래스 객체를 여러 번 생성할 수 있는 문제점
// => 가상 상속으로 해결
class Youngchul : public Chulsoo, public Younghee {
public:
	Youngchul() : Chulsoo(), Younghee() {
		cout << "Youngchul::Youngchul() 생성자 호출" << endl;
	}
	~Youngchul() {
		cout << "Youngchul::~Youngchul() 소멸자 호출" << endl;
	}
	void write() {
	// 다중 상속의 문제점 및 모호성
	// -> 자식 클래스가 다중상속을 받을 때 이름이 같은 멤버를
	// 호출할 수 있으므로, 호출 대상 멤버를 명확히 해야한다 !!
		Chulsoo::write();
	}
};

int main() {
	Youngchul youngchul;
	/*	파생 클래스 객체 생성 시 부모 클래스 부터 생성함
	
		Person::Person() 생성자 호출
		Chulsoo::Chulsoo() 생성자 호출
		Person::Person() 생성자 호출
		Younghee::Younghee() 생성자 호출
		Youngchul::Youngchul() 생성자 호출

		소멸은 역순 진행
	*/
	youngchul.write();
	return 0;
}