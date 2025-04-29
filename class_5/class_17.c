// 문자 입력 / 출력 함수
#include <stdio.h>
int main(void) {
	int ch1, ch2;
	ch1 = getchar(); // 문자 입력
	ch2 = fgetc(stdin); // enter 키 입력

	putchar(ch1); // 문자 출력
	fputc(ch2, stdout); // enter 키 출력

	return 0;
}