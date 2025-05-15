/*
	스마트포인터 : 포인터보다 다소 똑똑하게 동작하는 객체로
		"자신이 참조하는 객체의 소멸을 자동으로 해제" 해주는 똑똑한 포인터
*/

#include <iostream>
#include <memory>
using namespace std;
class Chulsoo {
private: 
	int age;
public:
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	Chulsoo() {
		cout << "Chulsoo::Chulsoo() 생성자 완료" << endl;
	}
	~Chulsoo() {
		cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
	}
	void introduce();
};

void Chulsoo::introduce() {
	cout << "철수 나이: " << age << endl;
}

int main() {
	// 기존 new & delete
	// Chulsoo* chulsooPtr2 = new Chulsoo(32);
	// chulsooPtr2->introduce();
	// delete chulsooPtr2;

	// smart pointer
	// 자신이 참조하는 객체의 소멸을 자동으로 해제
	auto_ptr<Chulsoo> chulsooSmptr(new Chulsoo(32));
	chulsooSmptr->introduce();
	return 0;
}