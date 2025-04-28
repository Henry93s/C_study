// class_1-15.c : 함수 내 함수 호출
#include <stdio.h>
int AbsoCompare(int num1, int num2); // 절댓값을 비교하고 절댓값이 큰 값을 반환하는 함수
int GetAbsoValue(int num); // 절댓값을 구하는 함수
int main() {
	int num1, num2;
	printf("두 개의 정수 입력: ");
	scanf_s("%d %d", &num1, &num2);
	printf("%d와 %d중 절댓값이 큰 정수: %d \n", num1, num2, AbsoCompare(num1, num2));
	
	return 0;
}
int AbsoCompare(int num1, int num2) {
	if (GetAbsoValue(num1) > GetAbsoValue(num2)) {
		return num1;
	}
	else {
		return num2;
	}
}
int GetAbsoValue(int num) {
	if (num < 0) {
		return num * (-1);
	}
	else {
		return num;
	}
}