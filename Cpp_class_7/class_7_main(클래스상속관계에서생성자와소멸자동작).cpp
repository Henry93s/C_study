#include "ConTest.h"
// 배경 : CON1 -> 기반 클래스, CON2 -> 파생 클래스
int main() {
	CON2* p_TEST = new CON2;
	// 1. 파생 클래스 객체 생성 전 기반 클래스 객체 먼저 생성
	// 2. 파생 클래스 객체 생성
	// 3. 파생 클래스 객체 소멸
	// 4. 기반 클래스 객체 소멸
	delete p_TEST;

	return 0;
}