
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
	Chulsoo() {
		this->age = 0;
	}
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	void introduce() {
		cout << "철수의 나이는 " << age << "세 입니다." << endl;
	}
	// 변형된 생성자 함수들 -> 연산자 오버로딩이 적용 전
	Chulsoo add(const Chulsoo& chulsooObj);
	Chulsoo sub(const Chulsoo& chulsooObj);
	Chulsoo mul(const Chulsoo& chulsooObj);
	Chulsoo div(const Chulsoo& chulsooObj);

	// 연산자 오버로딩 함수 선언
	Chulsoo operator+(const Chulsoo& chulsooObj);
	Chulsoo operator-(const Chulsoo& chulsooObj);
	Chulsoo operator*(const Chulsoo& chulsooObj);
	Chulsoo operator/(const Chulsoo& chulsooObj);

	int getAge() {
		return this->age;
	}
};

// 연산자 오버로딩이 적용 전
// 변형된 생성자 함수들
// => 기존 객체의 레퍼런스의 멤버와 연산 후 연산 결과를 생성자 매개변수로 전달
Chulsoo Chulsoo::add(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::add()" << endl;
	Chulsoo chulsoo(this->age + chulsooObj.age);
	return chulsoo;
}
Chulsoo Chulsoo::sub(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::sub()" << endl;
	Chulsoo chulsoo(this->age - chulsooObj.age);
	return chulsoo;
}
Chulsoo Chulsoo::mul(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::mul()" << endl;
	Chulsoo chulsoo(this->age * chulsooObj.age);
	return chulsoo;
}
Chulsoo Chulsoo::div(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::div()" << endl;
	Chulsoo chulsoo(this->age / chulsooObj.age);
	return chulsoo;
}

// 연산자 오버로딩 함수 정의
Chulsoo Chulsoo::operator+(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::operator+" << endl;
	Chulsoo chulsoo(this->age + chulsooObj.age);
	return chulsoo;
}
Chulsoo Chulsoo::operator-(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::operator-" << endl;
	Chulsoo chulsoo(this->age - chulsooObj.age);
	return chulsoo;
}
Chulsoo Chulsoo::operator*(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::operator*" << endl;
	Chulsoo chulsoo(this->age * chulsooObj.age);
	return chulsoo;
}
Chulsoo Chulsoo::operator/(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::operator/" << endl;
	Chulsoo chulsoo(this->age / chulsooObj.age);
	return chulsoo;
}

// 전역함수 연산자 오버로딩(은 아니지만 유사하게 작성 : 원래 int age 매개변수 x)
// 인자 2개 필요
Chulsoo operator+(int age, Chulsoo& chulsooObj2){
	// ! 3 + chulsoo1 로 받았을 때, int age = 3 인 Chulsoo 클래스의 객체가 생성됨(자동 형변환)
	cout << "전역변수 연산자 오버로딩 함수" << endl;
	Chulsoo chulsoo(age + chulsooObj2.getAge());
	return chulsoo;
}

int main() {
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);

	chulsoo1.introduce();
	chulsoo2.introduce();

	// 연산자 오버로딩이 적용 전
	/*
		Chulsoo chulsooAdd = chulsoo1.add(chulsoo2);
		chulsooAdd.introduce();
		Chulsoo chulsooSub = chulsoo1.sub(chulsoo2); 
		chulsooSub.introduce();
		Chulsoo chulsooMul = chulsoo1.mul(chulsoo2); 
		chulsooMul.introduce();
		Chulsoo chulsooDiv = chulsoo1.div(chulsoo2); 
		chulsooDiv.introduce();
	*/

	// 연산자 오버로딩이 적용
	Chulsoo chulsooAdd = chulsoo1 + chulsoo2; 
	// == chulsoo1.operator+(chulsoo2); 와 같은 함수 호출 규칙이 적용된다.
	chulsooAdd.introduce();
	Chulsoo chulsooSub = chulsoo1 - chulsoo2;
	chulsooSub.introduce();
	Chulsoo chulsooMul = chulsoo1 * chulsoo2;
	chulsooMul.introduce();
	Chulsoo chulsooDiv = chulsoo1 / chulsoo2;
	chulsooDiv.introduce();

	// 전역변수 오버로딩 적용
	cout << endl;
	Chulsoo chulsooGlobalAdd = 3 + chulsoo1; // 교환 법칙 주의!
	chulsooGlobalAdd.introduce();



	return 0;
}