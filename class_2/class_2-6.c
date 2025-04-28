// class_2-6.c : 비트 연산자
#include <stdio.h>
int main(void) {
	int num1 = 15; // 00001111
	int num2 = 20; // 00010100
	int num3 = num1 & num2; // num1 과 num2의 비트단위 & AND 연산
	printf("AND 연산의 결과: %d \n", num3); // 위 비트 확인 후 비트 연산에 따라 4 출력

	num3 = num1 | num2; // OR 연산
	printf("OR 연산의 결과; %d \n", num3); // 마찬가지로 비트 연산에 따라 00011111 -> 31 출력

	num3 = num1 ^ num2; // XOR 연산 : 서로 다른 경우에 1 비트 반환
	printf("XOR 연산의 결과: %d \n", num3); // 00011011 -> 27 출력

	num2 = ~num1; // NOT 비트 연산 : 0 은 1, 1 은 0 으로 보수연산
	printf("NOT 연산의 결과: %d \n", num2); // 11110000 -> 00001111 -> 00010000 에 - 부호를 붙이므로 -16

	// left shift : 왼쪽으로 1칸씩 비트 이동 연산 -> 정수 값이 2배씩 늘어남
	int result1 = num1 << 1; // num1 15 의 비트 열을 왼쪽으로 1칸씩 이동
	int result2 = num1 << 2; // num1 비트 열을 왼쪽으로 2칸씩 이동
	int result3 = num1 << 3; // num1 비트 열을 왼쪽으로 3칸씩 이동
	printf("num1 15 1칸 left shift 이동 결과 : %d \n", result1); // 00001111 -> 00011110 : 30 출력
	printf("num1 15 2칸 left shift 이동 결과 : %d \n", result2); // 00001111 -> 00111100 : 60 출력
	printf("num1 15 3칸 left shift 이동 결과 : %d \n", result3); // 00001111 -> 01111000 : 120 출력

	// right shift : 오른쪽으로 1칸씩 비트 이동 연산 -> 정수 값이 2로 나누어짐
	num1 = -16;
	printf("num1 -16 2칸 right shift 이동 결과 : %d \n", num1 >> 2); // 11110000 -> 11111100 : -4 출력 (2의 보수 후 - 부호)
	printf("num1 -16 3칸 right shift 이동 결과 : %d \n", num1 >> 3); // 00001111 -> 11111110 : -2 출력 (2의 보수 후 - 부호)

	return 0;
}