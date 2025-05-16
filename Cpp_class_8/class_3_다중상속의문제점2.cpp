#include <iostream>
using namespace std;

class BaseOne {
public:
	void SimpleFunc() {
		cout << "BaseOne" << endl;
	}
};

class BaseTwo {
public:
	void SimpleFunc() {
		cout << "BaseTwo" << endl;
	}
};

// 다중 상속 받음
// 상속 받은 멤버 중 이름이 같은 멤버가 있는지 확인하여 
// => 이름이 같은 멤버는 사용 시 클래스 이름을 명확히 해야함
class MultiDerived : BaseOne, BaseTwo {
public:
	void ComplexFunc () {
		BaseTwo::SimpleFunc();
		BaseOne::SimpleFunc();
	}
};

int main() {
	MultiDerived multi;
	multi.ComplexFunc();
}