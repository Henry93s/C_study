// class_9.c : 그 이외의 변환 함수들
// atoi, atol, atof : 문자열의 내용을 int / long / double 형으로 변환
// toupper, tolower : 대문자 / 소문자로 변환
// isdigit, isalpha, isalnum : 숫자 / 문자 / 숫자+문자 여부 확인
// isupper, islower : 대문자 / 소문자 여부 확인
// isspace : 공백 문자 여부 확인
#include <stdio.h>
#include <stdlib.h>
int main() {
	char str[20];
	printf("정수 입력: ");
	scanf_s("%s", str, sizeof(str));
	// 추가 : 문자열을 입력받을 때 마지막 글자가 널 문자 \0 으로 저장됨 !!
	// -> sizeof(str) 로 하고 20글자를 입력해도 최대 19글자까지만 저장 !
	printf("%d \n", atoi(str)); // 문자열을 정수로 변환

	printf("실수 입력: ");
	scanf_s("%s", str, sizeof(str));
	printf("%g \n", atof(str)); // 문자열을 실수로 변환

	return 0;
}

