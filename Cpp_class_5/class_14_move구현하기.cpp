#include <iostream>
using namespace std;

class Integer {
public:
	int* val;
	Integer() = default;
	Integer(int val) {
		this->val = new int(val);
	}
	// move 연산자 동작 구현
	Integer(Integer&& obj) {
		val = obj.val;
		obj.val = nullptr;
	}
	~Integer() {
		delete val;
	}
};

int main() {
	Integer i1(1);
	auto i2 = move(i1);
	cout << *i1.val << endl;
}