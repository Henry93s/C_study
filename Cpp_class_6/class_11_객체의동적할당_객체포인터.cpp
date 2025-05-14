#include <iostream>
using namespace std;

class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::chulsoo(age) 생성자 완료" << endl;
	}
	Chulsoo() {
		cout << "Chulsoo::Chulsoo() 생성자 완료" << endl;
	}
	~Chulsoo() {
		cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
	}

	void setAge(int age) {
		this->age = age;
	}
	void introduce();
};
void Chulsoo::introduce() {
	cout << " 철수 나이 : " << age << endl;
}

int main() {
	Chulsoo* chulsooPtr1 = (Chulsoo*)malloc(sizeof(Chulsoo));
	chulsooPtr1->setAge(44);
	chulsooPtr1->introduce();
	free(chulsooPtr1);
	
	// 객체 포인터 : 구조체 포인터와 동일한 방식으로 사용
	Chulsoo* chulsooPtr2 = new Chulsoo(55); // 생성자 완료 cout 확인
	chulsooPtr2->introduce();
	delete chulsooPtr2; // 소멸자 완료 cout 확인

	return 0;
}