// class_6.c : 문자열을 복사하는 함수 strcpy (strcpy_s, strncpy)
// -> strcpy 도 버퍼 오버플로우가 발생할 수 있음
// -> strcpy_s 를 사용하여 버퍼 오버플로우를 방지
// strncpy -> 복사될 배열의 길이를 넘어서지 않는 범위 내에서 복사 진행
#include <stdio.h>
#include <string.h>
int main() {
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	/**** case 1 ****/
	strcpy_s(str2, sizeof(str2), str1); // str2에 str1을 복사
	puts(str2); // str2 출력

	/**** case 2 ERROR ****/ 
	/*
	strncpy_s(str3, sizeof(str3), str1, sizeof(str3)); // str3에 str1을 복사
	puts(str3); // str3 출력
	*/

	/**** case 3 ****/
	strncpy_s(str3, sizeof(str3), str1, sizeof(str3) - 1); // str3에 str1을 복사
	str3[sizeof(str3) - 1] = '\0'; // str3의 마지막에 NULL 문자 추가
	puts(str3); // str3 출력

	return 0;
}