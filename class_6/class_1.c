// class_1.c : 문자열 단위 입출력 함수 (gets, puts)
#include <stdio.h>
int main(void) {
	char* str = "Simple String";

	printf("1. puts test ------ \n");
	puts(str); // 문자열이 선언된 위치에 문자열 주소값이 반환되므로 파라미터로 문자열 주소값이 전달됨
	puts("So Simple String"); // 

	printf("2. fputs test ------ \n");
	fputs(str, stdout); // stdout : 2번째 인자로 stdout 가 전달되어 모니터로 출력이 됨.
	printf("\n");
	fputs("So Simple String", stdout);
	printf("\n");

	printf("3. end of main ----\n");
	return 0;
}
