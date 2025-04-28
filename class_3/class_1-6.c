// class_1-6.c : if ~ else 조건문
#include <stdio.h>
int main() {
	int num;
	printf("정수 입력: ");
	scanf_s("%d", &num);

	// if ~ else 조건문은 조건이 참과 거짓의 두 가지 결과로 나뉠 때 사용함.
	if (num < 0) {
		printf("입력 값은 0보다 작다. \n");
	}
	else { 
		printf("입력 값은 0보다 작지 않다. \n");
	}

	return 0;
}