#include <iostream>
using namespace std;
class MyArray {
private:
	int num;
public:
	MyArray(int n) {
		cout << "생성자 호출" << endl;
		num = n;
	}
	MyArray(const MyArray& copy) {
		cout << "복사 생성자 호출" << endl;
		num = copy.num;
	}
	MyArray(MyArray&& move) {
		cout << "이동 생성자 호출" << endl;
		num = move.num;
		move.num = 0;
	}

	MyArray operator = (MyArray&& move) {
		cout << "이동 대입 연산자 호출" << endl;
		swap(num, move.num);
		return *this;
	}
	int getNum() {
		return num;
	}
};
MyArray CreateMyArray() {
	return MyArray(100);
}

int main() {
	MyArray ar1(10); // 생성자, 위에서 1번째 생성자
	MyArray ar2(ar1); // 복사 생성자, 위에서 2번째 생성자 
	cout << "ar1.getNum : " << ar1.getNum() << endl; // 10
	cout << "ar2.getNum : " << ar2.getNum() << endl; // 10

	ar2 = CreateMyArray(); /* == ar2 = MyArray(100);
		1. 생성자
		2. 이동 대입 "연산자"(= operator 연산으로 인해 할당됨)
		3. 복사 생성자(return 으로 인해 복사 생성자로 객체 생성 후 복사됨)
	*/
	cout << "ar1.getNum : " << ar1.getNum() << endl; // 10
	cout << "ar2.getNum : " << ar2.getNum() << endl; // 100

	MyArray ar3(move(ar1)); // 이동 생성자(move 개념), 위에서 3번째 생성자
	cout << "ar1.getNum : " << ar1.getNum() << endl; // move 로 인해 0
	cout << "ar3.getNum : " << ar3.getNum() << endl; // 10

	return 0;
}