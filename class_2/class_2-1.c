// class_2-1.c : 증가 감소 연산자
#include <stdio.h>
int main(void) {
	int num1 = 12;
	int num2 = 12;

	printf("num1: %d \n", num1);
	printf("num1++: %d \n", num1++); // 후위 증가 (연산 후 증가) -> 12 출력
	printf("num1: %d \n\n", num1); // 13 출력

	printf("num2: %d \n", num2);
	printf("++num2: %d \n", ++num2); // 전위 증가 (연산 전 증가) -> 13 출력
	printf("num2: %d \n\n", num2); // 13 출력

	return 0;
}