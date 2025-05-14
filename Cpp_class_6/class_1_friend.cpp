#include <iostream>
using namespace std;

class Chulsoo;

class Younghee {
private:
	int age;
public:
	Younghee(int age) : age(age) {
		cout << "Younghee::Younghee(age) 생성자 완료" << endl;
	}
	void introduce() {
		cout << "영희 나이: " << age << endl;
	}
	void whoIsOlder(const Chulsoo& chulsooObj);

	friend void howOldAreYou(const Chulsoo& chulsooObj, \
		const Younghee& youngheeObj);
	
};

class Chulsoo {
private:
	int age;

	
public:
	Chulsoo(int age) :age(age) {
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	void introduce() {
		cout << "철수 나이: " << age << endl;
	}

	// friend : 클래스 멤버가 private, protected 일 때, 지정한 클래스에서
	// private, protected 멤버로의 접근을 허용하도록 함

	// friend 클래스
	friend class Younghee;
	
	friend void howOldAreYou(const Chulsoo& chulsooObj, \
		const Younghee& youngheeObj);
};

// friend 함수
void Younghee::whoIsOlder(const Chulsoo& chulsooObj) {
	// Chulsoo 클래스에서 age 는 private 으로 지정되어 있어 외부에서 직접 접근 불가
	// => 해결 : Chulsoo 클래스 정의부에서 friend class Younghee; 로 선언 
	cout << "영희는 철수보다 " << ((age > chulsooObj.age) ? \
		"나이가 많다" : "나이가 적거나 같다") << endl;
}
void howOldAreYou(const Chulsoo& chulsooObj, const Younghee& youngheeObj) {
	cout << "철수는 " << chulsooObj.age << "살 입니다." << endl;
	cout << "영희는 " << youngheeObj.age << "살 입니다." << endl;
}

int main() {
	Chulsoo chulsoo1(32);
	chulsoo1.introduce();
	Younghee younghee1(35);
	younghee1.introduce();

	younghee1.whoIsOlder(chulsoo1);

	howOldAreYou(chulsoo1, younghee1);

	return 0;
}