#include <iostream>
using namespace std;

int assignValue(int* n) { // 포인터 매개변수 전달
	*n = 10; // 간접 참조 연산자 * 사용
	return *n;
}

class Restaurant {
public:
	int Steak; // 가격
};

class Chulsoo {
public:
	int Eat(int&); // 클래스 맴버 함수 선언, 레퍼런스 매개변수를 전달함
};

int Chulsoo::Eat(int& SteakPrice) { // 레퍼런스 매개변수 전달
	SteakPrice = 10000; // 변수의 또다른 이름인 레퍼런스 변수에 값을 할당
						// -> main 에서도 값이 변경된 값으로 출력됨
	cout << "철수는 먹는다" << endl;
	return 10000;
}

int main() {
	// 예제 1
	int num = 0, value;
	value = assignValue(&num);
	// 0 10
	cout << "[input] : " << num << " [output] : " << value << endl;

	// 예제 2
	Chulsoo chulsoo;
	Restaurant staurant;
	staurant.Steak = 20000;
	// 10000
	cout << "철수는 " << chulsoo.Eat(staurant.Steak) << "원 짜리 스테이크를 먹었다고 거짓말함" << endl;
	// 10000
	cout << "레스토랑은 철수가 " << staurant.Steak << "원 짜리 스테이크를 먹었다고 알고 있음" << endl;

	return 0;
}

