// class_1-18.c : static 지역 변수 
// static 변수 : 지역 변수와 전역 변수의 값 유지 특성을 모두 가지고 있음
// 1. 지역 변수(local) 특성 : 해당 함수가 반환하면 값이 소멸됨.
// 2. 전역 변수(global) 특성 : 프로그램 종료 시까지 메모리 공간에 값이 계속 존재함
// 3. 선언된 함수 내에서만 사용 가능하다(중괄호 포함) <- 지역 변수 o, 전역 변수 x
#include <stdio.h>
void SimpleFunc(void) {
	static int num1 = 0; // 초기화하지 않으면 0 초기화(static 지역 변수)
	int num2 = 0; // 초기화하지 않으면 쓰레기 값 초기화(지역변수)
	num1++, num2++;
	printf("static: %d, local: %d\n", num1, num2);
}
int main() {
	int i;
	for (i = 0;i < 3;i++) {
		SimpleFunc();
	}
	// i=0 : static : 1, local : 1
	// i=1 : static : 2, local : 1
	// i=2 : static : 3, local : 1

	return 0;
}