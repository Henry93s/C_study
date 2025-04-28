// class_2-7.c : sizeof 연산자 : 소모하는 메모리 크기를 "바이트" 단위로 계산해서 반환
#include <stdio.h>
int main(void) {
	char ch = 9;
	int inum = 1052;
	double dnum = 3.1415;
	printf("변수 ch의 크기: %d \n", sizeof(ch)); // 1
	printf("변수 inum의 크기: %d \n", sizeof(inum)); // 4
	printf("변수 dnum의 크기: %d \n", sizeof(dnum)); // 8

	printf("char의 크기: %d \n", sizeof(char)); // 1
	printf("int의 크기 : % d \n", sizeof(int)); // 4
	printf("long의 크기: %d \n", sizeof(long)); // 4 -> gcc 나 vscode 에서는 8 바이트로 출력됨 
	printf("long long의 크기: %d \n", sizeof(long long)); // 8
	printf("float의 크기: %d \n", sizeof(float)); // 4
	printf("double의 크기: %d \n", sizeof(double)); // 8
	/*  아래의 코드는 32bit, 64bit pc 모두 자료형의 크기를 보장하여 동일하게 출력됨
		printf("char : %lu\n", sizeof(int8_t)); // 1
		printf("short : %lu\n", sizeof(int16_t)); // 2
		printf("int : %lu\n", sizeof(int32_t)); // 4
		printf("long : %lu\n", sizeof(int64_t)); // 8
		printf("float : %lu\n", sizeof(float)); // 4
		printf("double : %lu\n", sizeof(double)); // 8

	*/

	return 0;
}
