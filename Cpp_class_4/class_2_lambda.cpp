#include <iostream>
using namespace std;

class Chulsoo {
public:
	void Eat(int SteakWeight);
	inline void EatInline(int SteakWeight); // 인라인 함수 선언
};


int main() {
	// 람다 함수 선언 + 호출
	[](int x, int y) {cout << "합은 " << x + y << endl;}(2, 3);// 5

	[](int SteakWeight) {cout << "eatLambda() :: 철수는 " << SteakWeight \
		<< "g 짜리 스테이크를 먹는다." << endl;}(1000);

	return 0;
}

void Chulsoo::Eat(int SteakWeight) {
	cout << "Eat() :: 철수는 " << SteakWeight \
		<< "g 짜리 스테이크를 먹는다." << endl;
}

inline void Chulsoo::EatInline(int SteakWeight) {
	// 인라인 함수 정의
	cout << "EatInline() :: 철수는 " << SteakWeight \
		<< "g 짜리 스테이크를 먹는다." << endl;
}