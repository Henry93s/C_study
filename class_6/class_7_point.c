// class_7.c ; 문자열을 붙이는 함수 strcat, strncat (_s)
// strncat : 문자열 끝에 널 문자를 자동으로 삽입
#include <stdio.h>
#include <string.h>
int main() {
	char str1[20] = "first~";
	char str2[20] = "second";

	char str3[20] = "Simple num: ";
	char str4[20] = "1234567890";

	/**** case 1 ****/
	strcat_s(str1, sizeof(str1), str2); // str1에 str2를 붙임
	puts(str1); // str1 출력

	/**** case 2 ****/
	strncat_s(str3, sizeof(str3), str4, 7); // str3에 str4를 붙임 (개행문자 포함)
	puts(str3); // str3 출력

	return 0;
}