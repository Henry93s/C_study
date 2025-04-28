/*
	도전 6. 프로그램 사용자로부터 초(second) 를 입력 받은 후, 이를 시, 분, 초 의 형태로 출력하는 프로그램 작성.
*/
#include <stdio.h>
int main(void) {
	int sec; // second 초 변수 선언
	printf("초(second) 입력: ");
	scanf_s("%d", &sec); // second 초 변수 입력 받음

	int h, m, s; // 시간, 분, 초 계산
	h = sec / 3600;
	m = sec % 3600 / 60;
	s = sec % 3600 % 60;
	printf("h: %d, m: %d, s: %d\n", h, m, s); // 시간 계산된 값을 출력한다.

	return 0;
}