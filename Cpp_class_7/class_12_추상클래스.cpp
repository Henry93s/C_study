// 추상 클래스 : 하나 이상의 순수 가상 함수 를 보유한 클래스
// - 순수 가상 함수 : 몸체가 없고 선언(=0)만 한 함수

#include <iostream>
#include <string>
using namespace std;

class AbstractClass {
public:
	virtual string SampleFunction() = 0; // 순수 가상 함수
};

class TestClass : public AbstractClass {
public:
	string SampleFunction() {
		return "SampleFunction";
	}
};

int main() {
	// AbstractClass obj1; // 추상 클래스는 직접 생성이 불가능함!
	// 추상 클래스는 상속 받아서 자식 클래스 객체로 생성하여 사용해야 한다.
	TestClass obj1;

	cout << obj1.SampleFunction() << endl;

	return 0;
}
