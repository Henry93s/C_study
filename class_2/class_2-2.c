// class_2-2.c : 관계, 논리 연산자
#include <stdio.h>
int main(void) {
	int num1 = 10;
	int num2 = 12;
	int result1, result2, result3;

	result1 = (num1 == 10 && num2 == 12); // num1 은 10 이고 num2 도 12 로 초기화 되었으므로 참 -> 1
	result2 = (num1 < 12 || num2 > 12); // num1 은 12 보다 작으므로 or 조건으로 인해 참 -> 1
	result3 = (!num1); // 0 이 아닌 값은 모두 참으로 취급하므로 이에 대한 ! not 조건은 거짓 -> 0

	printf("result1: %d \n", result1); // 1
	printf("result2: %d \n", result2); // 1
	printf("result3: %d \n", result3); // 0

	return 0;
}
