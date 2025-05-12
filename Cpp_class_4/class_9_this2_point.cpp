#include <iostream>
using namespace std;

class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) {
		this->age = age;
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	void setAge(int age) {
		this->age = age;
	}
	void introduce() {
		cout << "철수의 나이는 " << this->age << "세 입니다." << endl;
	}
	Chulsoo* returnThisPointer() {
		return this; // 객체 주소 반환
	}
	Chulsoo returnThis() {
		return *this; // ! 객체의 값 자체 반환 (call by value)
		// -> 메인 함수에서는 값이 복사 후 생성되어, 메인에서 변하더라도 
		// 객체 내부 멤버 값은 변하지 않는다.
	}
	Chulsoo& returnThisRef() {
		return *this; // 객체의 레퍼런스 반환
	}
};

int main() {
	Chulsoo chulsoo1(32);
	cout << "chulsoo1 객체 introduce" << endl;
	chulsoo1.introduce();
	chulsoo1.setAge(50);
	chulsoo1.introduce();

	Chulsoo chulsoo2(32);
	cout << "chulsooPointer introduce" << endl;
	chulsoo2.returnThisPointer()->introduce();
	chulsoo2.returnThisPointer()->setAge(50);
	chulsoo2.returnThisPointer()->introduce();

	Chulsoo chulsoo3(32);
	cout << "chulsoo introduce" << endl;
	chulsoo3.returnThis().introduce();
	chulsoo3.returnThis().setAge(50); // 값이 변하지 않음
	// 메인 함수로 값이 복사되는 의미이므로 객체 내부의 멤버 변수 값은 변하지 않음!
	chulsoo3.returnThis().introduce();

	Chulsoo chulsoo4(32);
	cout << "chulsoo4 introduce" << endl;
	chulsoo4.returnThisRef().introduce();
	chulsoo4.returnThisRef().setAge(51); // ref 변수를 가져왔으므로 . 참조 연산자
	// 를 통해 객체 맴버의 값 변경이 가능하다.
	chulsoo4.returnThisRef().introduce();

	return 0;
}