#include <iostream>
using namespace std;

class Chulsoo {
public:
	// int Eat(int SteakNum); // 일 때는 디폴트 인자 값을 지정하지 않아서 chulsoo.Eat() 에서 에러 발생
	int Eat(int SteakNum = 20000); // 디폴트 매개변수 지정으로 메인 함수 eat 실행이 정상 동작함
};

int main(void) {
	Chulsoo chulsoo;
	chulsoo.Eat();
	return 0;
}

int Chulsoo::Eat(int SteakNum) {
	cout << "철수는 " << SteakNum << "원짜리 스테이크를 먹는다" << endl;
	return SteakNum;
}