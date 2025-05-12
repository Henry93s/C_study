#include <iostream>
#include <string>
using namespace std;

int main() {
	// 람다식의 형식은 컴파일러만 알기 때문에
	// 개발자가 람다식을 저장하는 변수의 타입을 선언할 수 없으나, auto 로 저장할 수 있다.
	auto love = [](string a, string b) {
		cout << a << "보다 " << b << "가 좋아" << endl;
		};

	love("돈", "너");
	love("냉면", "만두");

	return 0;
}
