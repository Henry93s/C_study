#include <iostream>
#include <string>
using namespace std;

class MyClass {
public:
	MyClass() {}
	MyClass(string str) : m_str(str) {}

	void print() {
		cout << m_str << endl;
	}
private:
	string m_str;
};

int main() {
	MyClass A("aaa");
	MyClass B;
	MyClass C;
	B = A; // 복사
	C = move(A); // move 는 단순히 객체를 r-value 로 캐스팅하므로, 
	// 기본형 데이터 타입은 이동 연산을 지원하지 않아 단순 복사가 진행됨

	/*
	 r-value reference 
	: && 연산자를 통해 가능하며, 오직 r-value "임시 객체" 만을 참조하는 변수

	move : 실제로 객체를 복사시키지 않고, 인자로 넘어온 값을 r-value ref 로 캐스팅
	- == 소유권 이동 개념
	- => 값을 대입시킬 객체에는 r-value 레퍼런스를 넘겨서 메모리 주소를 그대로 전달
	- => 복사(copy) 를 피할 수 있어서, 메모리 및 시간 비용을 줄여 속도를 높일 수 있음.
	*/

	cout << "A print" << endl;
	A.print(); // 아무 출력이 되지 않음 (A 의 멤버 변수 소유권이 C 로 이동함)
	cout << "B print" << endl;
	B.print(); // 값 복사 "aaa"
	cout << "C print" << endl;
	C.print(); // A 의 멤버 변수 소유권이 C 로 이동함 "aaa"

	return 0;
}
