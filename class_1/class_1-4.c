// class_1-4.c : 연산자

#include <stdio.h>

int main() {
	int num1 = 3;	// num1 변수 선언 및 초기화
	int num2 = 4;	// num2 변수 선언 및 초기화
	int result = num1 + num2; // result 변수 선언 및 덧셈 결과 저장 

	printf("덧셈 결과: %d \n", result);
	printf("%d+%d=%d \n", num1, num2, result);
	printf("%d와(과) %d의 합은 %d입니다.\n", num1, num2, result);

	return 0;
}