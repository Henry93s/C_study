#include <iostream>
using namespace std;

class First {
public:
	void MyFunc() {
		cout << "First Func" << endl;
	}
};

class Second : public First {
public:
	void MyFunc() {
		cout << "Second Func" << endl;
	}
};

class Third : public Second {
public:
	void MyFunc() {
		cout << "Third Func" << endl;
	}
};

int main() {
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	// 함수를 호출할 때 사용된 포인터의 형에 따라서 호출되는 함수가 결정된다.
	fptr->MyFunc(); // first
	sptr->MyFunc(); // second
	tptr->MyFunc(); // third

	delete tptr;

	return 0;
}