// # : 선행처리 명령문
#include <stdio.h>
// 선행처리는 컴파일 전에 지정해 놓은 매크로를 매크로 값으로 단순 치환하는 작업

#define NAME "홍길동"
// 지시자 / 매크로 / 매크로몸체
#define AGE 24
#define PRINT_ADDR puts("주소: 경기도 용인시\n")

int main() {
	printf("이름: %s\n", NAME);
	printf("나이: %d\n", AGE);
	PRINT_ADDR;

	return 0;
}
