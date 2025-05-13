/*
	임시 객체 : 객체 없이 생성자를 호출할 때 생성됨
		- 다음 문장으로 넘어가려고 할 때 자동으로 소멸
		- return 값 : 임시 객체의 reference 값
*/
#include <iostream>
using namespace std;
class Temporary {
private:
	int num;
public:
	Temporary(int n) : num(n) {
		cout << "객체 생성: " << num << endl;
	}
	~Temporary() {
		cout << "객체 소멸: " << num << endl;
	}
	void ShowTempInfo() {
		cout << "객체 num : " << num << endl;
	}
};

int main() {
	Temporary(100); // 임시 객체 : 객체 없이 생성자 호출로 생성됨
	// -> "객체 생성" "객체 소멸" 후 아래 cout
	cout << "**** after make ! ****" << endl << endl;

	Temporary(200).ShowTempInfo(); 
	// -> "객체 생성" "객체 num" "객체 소멸" 후 아래 cout
	cout << "**** after make ! ****" << endl << endl;

	const Temporary ref = Temporary(300);
	// (const Temporary &ref = Temporary(300);)
	// -> "객체 생성" 후 ref (레퍼런스) 객체 변수가 임시 객체의 참조값(레퍼런스 변수 값)을 가지고 있음
	//     즉, 이 코드에서는 main 함수 종료 직전까지 소멸되지 않고 직전에 소멸됨
	cout << "end of main !" << endl;
	/* 여기서 ref 가 받은 ref (레퍼런스) 객체는 소멸됨 */ return 0;
}