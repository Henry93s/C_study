// 다중상속 : 하나의 클래스가 둘 이상의 클래스를 상속하는 형태
#include <iostream>
using namespace std;
class BaseOne {
public:
	void SimpleFuncOne() {
		cout << "BaseOne" << endl;
	}
};
class BaseTwo {
public:
	void SimpleFuncTwo() {
		cout << "BaseTwo" << endl;
	}
};

// 다중 상속 선언부 ( , 구분 )
class MultiDerived : public BaseOne, protected BaseTwo {
public:
	void ComplexFunc() {
		SimpleFuncOne();
		SimpleFuncTwo();
	}
};
int main() {
	MultiDerived mdr;
	mdr.ComplexFunc();

	return 0;
}