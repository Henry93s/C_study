#include <iostream>
using namespace std;
class SoSimple {
private:
	int num;
public:
	SoSimple(int n) : num(n) {
		cout << "생성자를 통해 생성되었음" << endl;
	}

	SoSimple(const SoSimple& copy) : num(copy.num) {
		cout << "복사 생성자를 통해 생성되었음" << endl;
	}

	void ShowData() {
		cout << num << endl;
	}
};
// call by value 방식의 함수 객체를 인자로 전달
void SimpleFuncObj(SoSimple obj) { 
	// case 2. SimpleFuncObj 함수 내 지역변수로 obj 가 초기화되는 과정에서 
	// obj 를 복사 생성자를 통해 생성해야함
	obj.ShowData();
}
int main() {
	SoSimple sim1(15);
	cout << "함수호출 전" << endl;
	
	// 복사 생성자
	// CASE 2. : call by value 방식의 함수 호출 과정에서 객체를 인자로 전달하는 경우
	SimpleFuncObj(sim1); 
	cout << "함수호출 후" << endl;
	return 0;
}