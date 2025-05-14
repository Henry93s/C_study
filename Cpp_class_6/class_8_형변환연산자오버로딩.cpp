#include <iostream>
using namespace std;

class Number {
private:
	int num;
public:
	Number(int n = 0) : num(n) {
		cout << "Number(int n=0)" << endl;
	}
	// operator= : 대입 연산자 오버로딩 함수
	Number& operator=(const Number& ref) {
		// Number 레퍼런스 객체를 받아서, Number 객체 생성자가 호출(Number 객체로 형변환)됨
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}

	// 형 변환 연산자 오버로딩
	// : 연산에서 객체가 int 형으로 형 변환이 필요할 때 형변환 연산자 오버로딩 함수가 호출됨
	operator int() {
		cout << "int 형 변환 연산자 오버로딩 함수 호출" << endl;
		return num;
	}

	void ShowNumber() {
		cout << num << endl;
	}
};

int main() {
	Number num1; // 기본 생성자
	num1.ShowNumber();
	cout << endl;

	num1 = 30; // num1.operator=(30); 와 같다.
	num1.ShowNumber(); // 30
	cout << endl;

	num1.operator=(50); // num1 = 50; 과 같다.
	num1.ShowNumber(); // 50
	cout << endl;

	// 1. num1 이 integer 형이 되어야 하므로 int 형 변환 연산자 오버로딩 함수 호출
	// 2. 80 으로 연산 결과를 받고, Number(int n=0) 생성자 호출
	Number num2 = (num1 + 30);
	num2.ShowNumber(); // 80
	cout << endl;

	return 0;
}