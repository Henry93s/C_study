#include <iostream>
using namespace std;

class Person {
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len]; // 생성자에서 멤버 변수의 메모리 공간 할당
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person() { // 소멸자 정의
		// => 생성자에서 멤버 변수에 메모리 공간을 동적할당할 경우 작성하는 것이 좋음.
		delete[] name; // 생성자에서 할당한 메모리 공간을 소멸
		cout << "called destructor!" << endl;
	}
};