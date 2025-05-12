#include "class_11_IntSample.h" // 클래스가 선언된 헤더파일을 가져오고 
// 정의는 소스 파일(cpp) 에서 정의한다.

void IntSample::ShowScore() {
	cout << "점수: " << Score << endl;
}
void IntSample::setScore(const int s) {
	Score = s;
}
int IntSample::getScore() {
	return Score;
}