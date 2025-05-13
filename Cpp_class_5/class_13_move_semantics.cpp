#include <iostream>
using namespace std;

class Integer {
public:
	int* val;
	Integer() = default;
	Integer(int val) {
		this->val = new int(val);
	}
	~Integer() {
		delete val;
	}
};

Integer Add(const Integer& a, const Integer& b) {
	Integer tmp; // default 생성자로 생성되고 지역변수 객체이므로 임시객체로 봄
	tmp.val = new int(a.val + b.val); 
	// tmp 는 지역변수 니까 return 전 소멸자 실행으로 에러발생
	return tmp;
}

int main() {
	Integer i1(1), i2(3);
	i1.val = Add(i1, i2).val;
	cout << i1.val << endl;

	auto i3 = move(i1);
	cout << *i1.val << endl;
}