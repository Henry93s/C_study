#include <iostream>
using namespace std;

int assignValue(int n) {
	n = 10;
	return n;
}
int testFunc(int n) {
	cout << n << endl; // 200
	n = 100;
	cout << n << endl; // 100
	return 0;
}

class Restaurant {
public:
	int Steak; // 가격
};

class Chulsoo {
public:
	int Eat(int); // 클래스 맴버 함수 선언
};

int Chulsoo::Eat(int SteakPrice) {
	SteakPrice = 10000;
	cout << "철수는 먹는다" << endl;
	return 10000;
}

int main() {
	// 예제 1
	int num = 0, value;
	// 주소가 매개변수로 가는 것이 아니라 해당 함수에서 생성된 "값" 을 리턴 받을 수 있음
	value = assignValue(num); 
	// 0 10
	cout << "[input] : " << num << " [output] : " << value << endl;

	// 예제 2
	num = 200;
	cout << "[input] : " << num << endl; // 200
	testFunc(num);
	cout << "[output] : " << num << endl; // 200

	// 예제 3
	Chulsoo chulsoo;
	Restaurant staurant;
	staurant.Steak = 20000;
	cout << "철수는 " << chulsoo.Eat(staurant.Steak) << "원 짜리 스테이크를 먹었다고 거짓말함" << endl;
	cout << "레스토랑은 철수가 " << staurant.Steak << "원 짜리 스테이크를 먹었다고 알고 있음" << endl;

	return 0;
}

