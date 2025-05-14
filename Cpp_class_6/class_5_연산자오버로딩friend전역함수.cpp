
#include <iostream>
/*
	오버로딩
	* 한 클래스 내에서 같은 이름의 메서드를 매개변수의 타입이나 개수를 다르게 정의
	오버라이딩
	* 상속 관계에서 자식 클래스가 부모 클래스의 메서드를 재정의

	연산자 오버로딩
	* 기본형에 대해서 사용하는 연산자의 의미를 확대해서 클래스 형에
	대해서도 사용할 수 있도록 만드는 기능
	* 오퍼레이터 함수 선언 -> 정의 -> 적용
	* 함수 호출 규칙 : (멤버함수를 호출할 객체) (연산자) (함수 전달인자)
		-> ex. pos1 + pos2;
	=> chulsoo1.operator+(chulsoo2); 와 같은 함수를 + 연산자로 사용할 수 있게하므로
		연산자 오버로딩이라고 함.

*/
using namespace std;
class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	void introduce() {
		cout << "철수의 나이는 " << age << "세 입니다." << endl;
	}
	
	// friend : 클래스 멤버가 private, protected 일 때, 지정한 클래스에서
	// private, protected 멤버로의 접근을 허용하도록 함

	// 연산자 오버로딩 함수를 friend 로 선언하여 
	// 전역에서 private 멤버에 접근이 가능하도록 함
	friend Chulsoo operator+(const Chulsoo& chulsooObj1, const Chulsoo& chulsooObj2);
};

// 연산자 오버로딩 friend 전역 함수 정의
// => 연산자 오버로딩 함수를 전역으로 사용하므로 추가 인자가 필요함
Chulsoo operator+(const Chulsoo& chulsooObj1, const Chulsoo& chulsooObj2) {
	// ! 3 + chulsoo1 로 받았을 때, int age = 3 인 Chulsoo 클래스의 객체가 생성됨(자동 형변환)
	cout << "\n연산자 오버로딩 전역 함수 operator+()" << endl;
	Chulsoo chulsoo(chulsooObj1.age + chulsooObj2.age); // 객체 생성 후 반환
	return chulsoo;
}

int main() {
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);

	chulsoo1.introduce();
	chulsoo2.introduce();

	// 연산자 오버로딩 friend 전역 함수 사용
	Chulsoo chulsooAdd = 3 + chulsoo1;
	chulsooAdd.introduce();

	return 0;
}