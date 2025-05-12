#include "class_11_IntSample.h" // 클래스가 선언된 헤더파일만을 불러옴 !
// => 소스 파일 cpp 를 include 시 중복 정의 오류가 발생하여 선언부인 헤더파일을 include 해야함

int main() {
	IntSample Obj;
	Obj.setScore(100);
	cout << "점수: " << Obj.getScore() << endl;

	return 0;
}