// class_4.c : 
#include <stdio.h>
int main(int argc, char* argv[]) {
	int i;
	float f;
	char c, str[32];

	scanf_s("%d", &i);
	printf("정수 : %d\n", i);
	scanf_s("%f", &f);
	printf("실수: %f\n", f);
	// - 이전에 숫자를 입력 받고나서 남은 입력 버퍼에 개행문자를 비우는 방법
	// 1. 입력 버퍼 지우는 방법 (while getchar() != '\n'); 
	/*
		while (getchar() != '\n');
		scanf_s("%c", &c, 1);
	*/

	// 2. 공백을 사용하여 개행 문자를 무시하는 방법
	// scanf_s(" %c", &c, 1); 
	
	// 3. %*c를 사용하여 개행 문자 무시
	scanf_s("%*c%c", &c, 1); 
	
	printf("문자: %c\n", c);
	
	scanf_s("%s", str, 32); 
	printf("문자열: %s\n", str);

	return 0;
}