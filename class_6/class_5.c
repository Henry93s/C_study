// class_6.c: 문자열의 길이를 반환하는 함수 strlen (string.h)
#include <stdio.h>
#include <string.h>
void RemoveBSN(char str[]) {
	int len = strlen(str);
	str[len - 1] = '\0'; // 문자열 마지막 문자를 '\0' 으로 강제 변경하여 개행문자 제거
}
int main() {
	char str[100];
	printf("문자열 입력: ");
	fgets(str, sizeof(str), stdin);
	// fgets 는 개행문자도 포함하여 저장함 (scanf_s는 개행문자 포함 안됨 -> 버퍼에 남아있음 !)
	printf("길이: %d, 내용: %s\n", strlen(str), str);

	RemoveBSN(str); // 개행문자 제거
	printf("길이: %d, 내용: %s\n", strlen(str), str);
	
	return 0;
}