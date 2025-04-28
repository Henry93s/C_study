// class_2-8.c : sizeof 연산자
#include <stdio.h>
int main(void) {
	char num1 = 1, num2 = 2, result1 = 0;
	short num3 = 300, num4 = 400, result2 = 0;

	printf("size of num1 & num2: %d, %d \n", sizeof(num1), sizeof(num2)); // 1, 1
	printf("size of num3 & num4: %d, %d \n", sizeof(num3), sizeof(num4)); // 2, 2

	printf("size of char add: %d \n", sizeof(num1 + num2)); // 4 (1 + 2 후 sizeof 를 출력하기 때문에 int 타입 데이터 크기 4)
	printf("size of short add: %d \n", sizeof(num3 + num4)); // 4 (300 + 400 후 sizeof 를 출력하기 때문에 int 타입 데이터 크기 4)

	result1 = num1 + num2;
	result2 = num3 + num4;
	printf("size of result1 & result2: %d, %d \n", sizeof(result1), sizeof(result2)); // 1, 2 (이미 저장된 변수에 대한 타입 데이터 크기 이므로 각각 char, short = 1, 2) 
	return 0;
}