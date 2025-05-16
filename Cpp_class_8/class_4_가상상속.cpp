
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
	void sleep() {
		cout << "잔다" << endl;
	}
};

// virtual public Person : 가상 상속
// -> 중복되는 기반 클래스(부모 클래스) 를 한 번만 생성하도록 한다.
class Chulsoo : virtual public Person {
public:
	Chulsoo() : Person() {
		cout << "Chulsoo::Chulsoo() 생성자 호출" << endl;
	}
	~Chulsoo() {
		cout << "Chulsoo::~Chulsoo() 소멸자 호출" << endl;
	}
	void write() {
		cout << "책을 잘 쓴다" << endl;
	}
};

class Younghee : virtual public Person {
public:
	Younghee() : Person() {
		cout << "Younghee::Younghee() 생성자 호출" << endl;
	}
	~Younghee() {
		cout << "Younghee::~Younghee() 소멸자 호출" << endl;
	}
	void write() {
		cout << "책을 못 쓴다" << endl;
	}
};

class Youngchul : public Chulsoo, public Younghee {
public:
	Youngchul() : Chulsoo(), Younghee() {
		cout << "Youngchul::Youngchul() 생성자 호출" << endl;
	}
	~Youngchul() {
		cout << "Youngchul::~Youngchul() 소멸자 호출" << endl;
	}
	void write() {
		Chulsoo::write();
	}
};

int main() {
	Youngchul youngchul;
	/* 
	* Younghee 의 부모 클래스 생성자로 객체를 생성하려고 할 때
	* Chulsoo 클래스 생성자를 통해서 이미 같은 부모 클래스 객체가
	* 생성되었음 -> 가상 상속으로 Younghee, Chulsoo 클래스가 선언됨
	* ==> Person 클래스 객체가 한 번만 생성된다.
	* 
	Person::Person() 생성자 호출
	Chulsoo::Chulsoo() 생성자 호출
	Younghee::Younghee() 생성자 호출
	Youngchul::Youngchul() 생성자 호출
	*/
	youngchul.write();

	youngchul.sleep(); 
	// Younghee, Chulsoo 클래스 정의 시 virtual
	// 키워드를 뺄 경우 영희 부모 멤버인지 철수 부모 멤버인지 
	// 접근이 모호해서 에러가 발생함 !

	return 0;
}