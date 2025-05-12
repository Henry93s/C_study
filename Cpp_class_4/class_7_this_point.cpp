// this : this 가 사용된 객체 자신의 주소값 정보를 담고 있는 포인터 !
#include <iostream>
using namespace std;
class X {
protected:
	int m_data;

public:
	void Set(int size); // 생성자
	bool IsEquivalent(const X& object);
	bool IsSame(const X& object);
	void GetData(int& getValue);
};

bool X::IsEquivalent(const X& object) { // 값이 같은지 비교하는 함수
	return (m_data == object.m_data);
}
bool X::IsSame(const X& object) { // 객체가 같은지 비교하는 함수
	return (this == &object);
}
void X::Set(int size) {
	this->m_data = size;
}
void X::GetData(int& getValue) {
	getValue = this->m_data;
}

int main() {
	X obj1;
	obj1.Set(100);
	int getValue;

	X obj2 = obj1; // 새 obj2 객체를 생성하고 obj1 을 복사했으므로
	if (obj1.IsSame(obj2)) { // 비교 시 서로 "다른 객체"
		cout << "동일 객체" << endl;
	}
	else {
		obj1.GetData(getValue);
		cout << "obj1 in data value : " << getValue << endl;
		cout << "obj1 address : " << &obj1 << endl;
		obj2.GetData(getValue);
		cout << "obj2 in data value : " << getValue << endl;
		cout << "obj2 address : " << &obj2 << endl; // 객체 주소 비교 시 다름
		cout << "다른 객체" << endl;
	}

	X& obj3 = obj1; // 레퍼런스 변수이므로
	if (obj1.IsSame(obj3)) { // 비교 시 "동일 객체"
		obj1.GetData(getValue);
		cout << "obj1 in data value : " << getValue << endl;
		cout << "obj1 address : " << &obj1 << endl;
		obj3.GetData(getValue);
		cout << "obj3 in data value : " << getValue << endl;
		cout << "obj3 address : " << &obj3 << endl; // 객체 주소 비교 시 같음
		cout << "동일 객체" << endl;
	}
	else {
		cout << "다른 객체" << endl;
	}

	return 0;
}