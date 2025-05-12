#include <iostream>
using namespace std;

class Chulsoo {
public:
	int count;
};
int main() {
	Chulsoo chulsoo;
	chulsoo.count = 1;

	// 캡쳐(=) : (value) 
	// "mutable" 필요
	// (call by value 로 받아서 람다식 내부에서 값 변경을 위함, 당연히 메인 함수 원본 값은 변경되지 않음)
	for (int i = 0;i < 10;i++) {
		[=](int steakWeight) mutable {cout << "eatLambda() :: 철수는 " << chulsoo.count++ \
			<< "번째 " << steakWeight << "g 짜리 스테이크를 먹는다" << endl;}(1000);
	}

	cout << "[=] " << chulsoo.count << endl;
	cout << "\n";

	// 반환형을 char 로 지정한 람다 함수
	cout << [=](int steakWeight)mutable->char {cout << "eatLambda() :: 철수는 " \
		<< chulsoo.count++ << "번째 " << steakWeight << "g 짜리 스테이크를 먹는다." << endl;
	return steakWeight;	}(67) << endl; // 65 = 'A' 이므로 67 이 char 로 반환되면 C 출력
	// 반환형을 int 로 지정한 람다 함수
	cout << [=](int steakWeight)mutable->int {cout << "eatLambda() :: 철수는 " \
		<< chulsoo.count++ << "번째 " << steakWeight << "g 짜리 스테이크를 먹는다." << endl;
	return steakWeight;}(76) << endl;
	// 반환형을 지정하지 않았지만, steakWeight 를 반환하므로 int
	cout << [=](int steakWeight)mutable {cout << "eatLambda() :: 철수는 " \
		<< chulsoo.count++ << "번째 " << steakWeight << "g 짜리 스테이크를 먹는다." << endl;
	return steakWeight;}(88) << endl;


	// 캡쳐(&) : (reference)
	for (int i = 0;i < 10;i++) {
		[&](int steakWeight) {cout << "eatLambda() :: 철수는 " << chulsoo.count++ \
			<< "번째 " << steakWeight << "g 짜리 스테이크를 먹는다" << endl;}(1000);
	}

	cout << "[&] " << chulsoo.count << endl;

	return 0;
}