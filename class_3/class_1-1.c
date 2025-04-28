// class_1-1.c : do while -> 처음 while 문을 무조건 실행하고 반복문 조건 확인
#include <stdio.h>
int main() {
	int total = 0, num = 0;

	do { // 1. 조건과 관계없이 일단 한 번은 반복문을 실행한다.
		printf("정수 입력(0 to quit): "); // 2. 반복문
		scanf_s("%d", &num);
		total += num;
	} while (num != 0); // 3. do~while 조건 확인
	printf("합계: %d \n", total);

	return 0;
}