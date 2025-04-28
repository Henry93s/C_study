// class_2-4.c : scanf 함수의 이해
/*
	scanf("%d", &val);
	-> 10진수 정수형을 입력 받아서 변수 val에 저장
*/
#include <stdio.h>
int main(void) {
	int result;
	int num1, num2;

	printf("정수: one: ");
	scanf_s("%d", &num1); // 첫 번째 정수 입력 후 변수 num1 에 저장
	// build 시 scanf 대신 secure coding 으로 scanf_s 사용 권장됨
	/*
		CERT C : C 언어 보안 취약점 방지를 위한 시큐어 코딩 표준
		CERT C 표준에 의하여 scanf 사용 시 컴파일 에러가 발생함
	*/
	printf("정수: two: ");
	scanf_s("%d", &num2); // 두 번째 정수 입력 후 변수 num2 에 저장

	result = num1 + num2;
	printf("%d + %d = %d \n", num1, num2, result);
	return 0;
}