// class_1-3.c : 변수 선언 및 초기화

#include <stdio.h>

int main(void) {
	int num1, num2; // 변수 num1, num2 의 선언
	/*
		지역변수일 때 선언만 한 경우 : 쓰레기 값으로 초기화
		전역변수일 때 선언만 한 경우 : 0 으로 초기화
	*/
	int num3 = 30, num4 = 40; // 변수 num3, num4 의 선언 및 초기화

	// 수정 후 : 아래 printf 에서 변수 호출 전에 변수 num1, num2 를 초기화하여 빌드 시 런타임 에러가 발생되지 않음
	num1 = 10; num2 = 20;
	printf("num1: %d, num2: %d\n", num1, num2);
	/* 수정 전 : 위 printf 에서 변수 호출 전에 변수가 초기화되지 않아 에러 발생 -> 주석 처리로 문장에서 제외 */
	/*
		num1 = 10; // 변수 num1 초기화
		num2 = 20; // 변수 num2 초기화
	*/

	printf("num1: %d, num2: %d \n", num1, num2);
	printf("num3: %d, num4: %d \n", num3, num4);
	return 0;
}