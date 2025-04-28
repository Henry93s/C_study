/*
도전 1.
10진수 정수를 입력 받아서 16진수로 출력하는 프로그램 작성하기.
서식문자의 활용에 대한 문제.
*/
#include <stdio.h>
int main(void) {
	int num; // 입력받을 10진수 정수 변수 선언
	scanf_s("%d", &num); // num 변수에 정수를 입력 받음.

	printf("%#x\n", num); // %#x 로 # 을 % 와 x 사이에 추가해서 16진수임을 확실하게 표현

	return 0;
}