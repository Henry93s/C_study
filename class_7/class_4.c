// typedef 선언
// 기존에 존재하는 자료형의 이름에 또다른 새 이름을 부여하는 것
// -> 포인터 변수를 선언할 수도 있음
#include <stdio.h>
typedef int INT;
typedef int* PTR_INT;

typedef unsigned int UINT;
typedef unsigned int* PTR_UINT;

typedef unsigned char UCHAR;
typedef unsigned char* PTR_UCHAR;

int main() {
	INT num1 = 120; // int num1 = 120;
	PTR_INT pnum1 = &num1; // int* pnum1 = &num1;

	UINT num2 = 190; // unsigned int num2 =190;
	PTR_UINT pnum2 = &num2; // unsigned int* pnum2 = &num2;

	UCHAR ch = 'Z'; // unsigned char ch = 'Z';
	PTR_UCHAR pch = &ch; // unsigned char* pch = &ch;

	printf("%d, %u, %c \n", *pnum1, *pnum2, *pch); // 120, 190, Z

	return 0;
}