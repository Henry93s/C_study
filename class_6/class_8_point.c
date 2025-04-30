// class_8.c : 문자열을 비교하는 함수 strcmp, strncmp
// s1 이 더 크면 1, s2 가 더 크면 -1, 같으면 0
// strncmp : n글자 비교
#include <stdio.h>
#include <string.h>
int main() {
	char str1[20];
	char str2[20];

	printf("문자열 입력 1: ");
	scanf_s("%s", str1);
	printf("문자열 입력 2: ");
	scanf_s("%s", str2);

	if (!strcmp(str1, str2)) { // strcmp : 문자열 비교
		printf("같은 문자열입니다.\n");
	}
	else {
		printf("다른 문자열입니다.\n");
		if (!strncmp(str1, str2, 3)) { // strncmp : 문자열 비교 (n글자)
			printf("앞의 3글자는 같습니다.\n");
		}
		else {
			printf("앞의 3글자는 다릅니다.\n");
		}
	}

	return 0;
}