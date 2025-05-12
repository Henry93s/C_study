#include <iostream>
#include <string>
using namespace std;
#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20

// c++ 에서의 구조체 : c 와는 달리 맴버에 함수를 포함시킬 수 있음
// -> 편의상 c++ 에서 맴버에 함수가 있을 때 클래스라고 말하기도 함
// struct Chulsoo

class Chulsoo // struct -> class 로 변경 시 기본 접근 지정자가 private 이므로,
	// 별도로 접근 지정자를 설정해주어야함(ex. public)
{
public: // 별도로 접근 지정자를 설정해주어야함(ex. public)
	char name[NAME_LEN];
	char sex[SEX_LEN];
	char job[JOB_LEN];
	char character[CHARACTER_LEN];
	int age;

	void introduce() {
		cout << "소개 : " << name << endl;
	}
	void eat(string food) {
		cout << food << " 먹는다.\n";
	}
	void sleep() {
		cout << "잠" << endl;
	}
	void drive(string destination) {
		cout << destination << " 로 이동\n";
	}
};

int main() {
	Chulsoo chulsoo = { "철수", "남성", "작가", "diligent", 32};

	chulsoo.drive("레스토랑");
	chulsoo.eat("스테이크");

	return 0;
}