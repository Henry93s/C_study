#include <iostream>
using namespace std;
class Person {
private:
	int age;
	char name[50];
public:
	Person(int myage, char* myname) : age(age) {
		strcpy_s(name, 50, myname);
	}
	void WhatYourName() const { // const : 변경이 발생하지 않는 함수
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const {
		cout << "'I'm " << age << " years old" << endl;
	}
};

// : extends
// 상속 클래스 : 부모(Person) 클래스의 멤버를 상속 받는 클래스. 
class UnivStudent : public Person { // public : 상속받는 방식
private: 
	char major[50];
public:
	UnivStudent(char* myname, int myage, char* mymajor)
		: Person(myage, myname)
		// !!  : extends Person(myage, myname) 생성자가 있어야 자식클래스가 생성된다.
	{
		strcpy_s(major, 50, mymajor);
	}
	void WhoAreYou() const {
		WhatYourName(); // 부모 클래스에서 상속받은 멤버 함수
		HowOldAreYou(); // 부모 클래스에서 상속받은 멤버 함수
		cout << "My major is " << major << endl << endl;
	}
};