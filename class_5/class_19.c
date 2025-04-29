// 423p 문제 21-1. 문자 대소문자 변환
#include <stdio.h>
int main() {
	char a = getchar();

	if (a >= 97 && a <= 122) { // 소문자 a 아스키코드 97 ~ 122
		putchar(a - 32);
	}
	else if(a >= 65 && a <= 90){ // 대문자 아스키코드 65 ~ 90
		putchar(a + 32);
	}
	else {
		printf("INPUT ERROR !\n");
	}

	return 0;
}