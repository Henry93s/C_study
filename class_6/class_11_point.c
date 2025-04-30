// 445 p 21-2 문제 2. scanf_s 에서 문자열 받을 때는 개행문자가 포함 x, 
// gets 나 fgets 로 문자열 받을 때는 개행문자가 포함됨
// -> 개행문자 필요 시 마지막 문자를 '\0' 널 문자로 강제 변경
#include <stdio.h>
#include <string.h>
int main() {
	char str1[20];
	char str2[20];
	char str3[40];

	fgets(str1, 20, stdin);
	str1[strlen(str1) - 1] = '\0'; // 내부에 있는 개행 문자를 강제로 널문자로 변경 
	fgets(str2, 20, stdin);
	str2[strlen(str2) - 1] = '\0';

	strncpy_s(str3, 40, str1, 20); // str3 에 str1 문자열 복사
	strncat_s(str3, 20, str2, 20); // str3 에 str2 문자열 붙이기

	printf("%s\n", str3);
}