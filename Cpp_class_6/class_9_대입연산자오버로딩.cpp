#include <iostream>
using namespace std;

class Chulsoo {
private: 
	int age;
public:
	Chulsoo(const Chulsoo& source) : age(source.age) {
		cout << "Chulsoo::chulsoo() 복사 생성자 완료" << endl;
	}
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	Chulsoo() {
		cout << "Chulsoo::Chulsoo() 생성자 완료" << endl;
	}
	void introduce();
	~Chulsoo() {
		cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
	}

	// 대입 연산자 오버로딩 함수 정의
	// friend Chulsoo operator=(const Chulsoo& src1, const Chulsoo& src2);
	// -> 대입 연산자 오버로딩 시 전역 함수로는 허용하지 않음 !
	Chulsoo& operator=(const Chulsoo& source) {
		this->age = source.age;
		cout << "Chulsoo::operator=() 복사 대입 연산자 완료" << endl;
		return *this;
	}
};

void Chulsoo::introduce() {
	cout << "나이: " << age << endl;
}

int main() {
	Chulsoo chulsoo1(32);
	Chulsoo chulsoo2(50);
	Chulsoo chulsoo3(20);
	chulsoo1.introduce();
	chulsoo2.introduce();
	chulsoo3.introduce();
	cout << "======== 대입 연산 전 ========" << endl;
	chulsoo1 = chulsoo2; // 대입 연산자 오버로딩 함수가 없을 때 디폴트 대입 연산자가 사용됨
	// chulsoo1.operator=(chulsoo2);
	chulsoo2.operator=(chulsoo1); // chulsoo2 = chulsoo1 과 같다.
	chulsoo1 = chulsoo2 = chulsoo3;
	cout << "======== 대입 연산 후 ========" << endl;
	chulsoo1.introduce();
	chulsoo2.introduce();
	chulsoo3.introduce();

	return 0;
}