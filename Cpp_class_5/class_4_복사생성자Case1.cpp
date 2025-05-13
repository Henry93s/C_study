#include <iostream>
using namespace std;
class SoSimple {
private:
	int num1;
	int num2;
	int* num3;
public:
	SoSimple(int n1, int n2) :num1(n1), num2(n2){
		cout << "생성자를 통해 sim2 가 생성되었음" << endl;
		num3 = &num2;
	}
	// 자동으로 삽입되는 디폴트 복사 생성자(과정을 보기 위해 c out 문 작성)
	SoSimple(const SoSimple &copy): num1(copy.num1), num2(copy.num2), num3(copy.num3) {
		// num3 에서 얕은 복사 발생
		// 얕은 복사 : 포인터 변수를 복사하여 주소만 복사되는 것
		// (깊은 복사 : 포인터 변수가 가리키는 데이터를 복사하는 것)
		cout << "복사 생성자를 통해 sim2 가 생성되었음" << endl;
	}
	
	void ShowSimpleData()  {
		cout << num1 << endl;
		cout << num2 << endl;
		cout << num3 << endl;
	}
};

int main() {
	SoSimple sim1(15, 20);
	cout << "test" << endl;
	// 복사 생성자 : CASE 1. 이미 만들어진 객체를 통해 객체를 "초기화" 하는 생성자
	// 복사 생성자로 인해 멤버 대 멤버 "값" 의 복사가 일어난다.
	/*
		- 컴파일러에 의해 자동 생성되나
		- 멤버 변수가 포인터 멤버일 때는 단순히 그 주소가 복사되기 때문에 
		  별도의 복사 생성자를 정의할 필요가 있다.
	*/
	// 복사 생성자
	// CASE 1. 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우
	SoSimple sim2 = sim1; // == SoSimple sim2(sim1)

	sim1.ShowSimpleData();
	sim2.ShowSimpleData();

	// sim2 의 num3 는 sim1 의 num3 값을 얕은 복사로 주소를 복사했기 때문에
	// sim1 과 sim2 를 delete 하거나, 둘 중 한 객체에서 num3 의 값을 수정하려할 때 문제가 발생함
	return 0;
}