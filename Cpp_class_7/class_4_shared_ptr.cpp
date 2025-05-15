/*
	shared_ptr : unique_ptr 과 달리 "공유" 개념이 적용되어 
	여러 스마트 포인터가 특정 객체를 참조할 수 있음.
	- 하나의 특정 객체를 참조하는 스마트 포인터가 총 몇개인지를 참조하는 
		스마트 포인터
	-> 복사 생성자, 대입을 통한 초기화가 가능함

	참조 횟수( use_count() ) : 참조하고 있는 스마트 포인터(소유자)의 개수
	- '소유자' 자체는 확인할 수 없음
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
	shared_ptr<int> ptr01(new int(5));
	cout << ptr01.use_count() << endl; // 1
	auto ptr02(ptr01); // 복사 생성자를 통한 초기화
	cout << ptr01.use_count() << endl; // 2
	auto ptr03 = ptr01; // 대입을 통한 초기화
	cout << ptr01.use_count() << endl; // 3

	auto ptr04 = ptr03; // 대입을 통해 직전 초기화한 ptr03 을 src 로 초기화
	cout << ptr01.use_count() << endl; // 4
	cout << ptr04.use_count() << endl; // 4

	shared_ptr<Chulsoo> chulsooSmptr1(new Chulsoo(32));
	// chulsooSmptr1 생성자 실행
	cout << chulsooSmptr1.use_count() << endl; // 1
	chulsooSmptr1->introduce();

	cout << "shared_ptr<Chulsoo> 타입 간 대입 및 복사 생성자 호출 후" << endl;
	shared_ptr<Chulsoo> chulsooSmptr2 = chulsooSmptr1;
	// 참조 발생(생성 x)
	shared_ptr<Chulsoo> chulsooSmptr3(chulsooSmptr1);
	// 참조 발생(생성 x)
	cout << chulsooSmptr1.use_count() << endl; // 3
	chulsooSmptr1->introduce(); // 32
	chulsooSmptr2->introduce(); // 32

	// chulsooSmptr1 소멸자 실행
	return 0;
}