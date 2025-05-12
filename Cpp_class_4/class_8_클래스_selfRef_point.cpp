#include <iostream>
using namespace std;

class SelfRef {
private:
	int num;
public:
	SelfRef(int n) : num(n) {
		cout << "객체 생성" << endl;
	}
	SelfRef& Adder(int n) {
		num += n;
		return *this; // 객체의 레퍼런스를 반환 
	}
	SelfRef& ShowTwoNumber() {
		cout << num << endl; 
		return *this; // 객체의 레퍼런스를 반환
	}
};

int main() {
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2); // 레퍼런스 변수에 의해 obj 도 변화

	obj.ShowTwoNumber(); // 5 (레퍼런스 변수 ref 영향)
	ref.ShowTwoNumber(); // 5

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber(); // 6 , 8

	return 0;
}