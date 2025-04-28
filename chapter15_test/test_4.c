// 문제 4. palindrome 회문 판단 프로그램(대소문자까지 일치해야 회문으로 인정)
#include <stdio.h>
#include <string.h> // strlen 함수를 사용하기 위해서 헤더 파일 추가
int isPalindrome(char str[]) {
	int i;
	int s = 0, e = strlen(str); // strlen 함수 : str 문자열의 길이를 반환한다.
	// 또는 문자열의 문자를 순회해서 '\0' 인 값을 찾는다.
	int isTrue = 1;
	for (i = s;i < e / 2;i++) {
		if (str[i] != str[e - i - 1]) {
			isTrue = 0;
			break;
		}
	}
	return isTrue;
}
int main() {
	char str[1000];

	printf("문자열 입력: ");
	scanf_s("%s", str, 1000);
	// scanf_s 에서 문자열 입력 시 마지막 파라미터에 크기를 지정해야 함.
	
	int isTrue = 0;
	isTrue = isPalindrome(str);
	if (isTrue) {
		printf("회문입니다.\n");
	}
	else {
		printf("회문이 아닙니다.\n");
	}

	return 0;
}