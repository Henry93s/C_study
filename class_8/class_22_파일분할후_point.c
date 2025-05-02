#include <stdio.h>
extern int num; // num 은 외부 파일에서 선언된 변수임을 표시
// !!! 전역변수에서의 static :  외부 파일에서 int num = 0; 이 아닌
// static int num = 0; 으로 선언했을 때에는 다른 파일에서 해당 변수에 접근할 수 없음 !!
extern void Increment(); // Increment 함수도 extern 선언으로 외부에 있는 함수임을 표시
extern int GetNum();
// 함수도 외부에서 static void Increment() 처럼 외부 파일에서 선언했을 땐
// 마찬가지로 접근할 수 없다.

int main(void) {
	printf("num: %d\n", GetNum());
	Increment();
	printf("num: %d\n", GetNum());
	Increment();
	printf("num: %d\n", GetNum());

	return 0;
}