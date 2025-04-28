// class_1-23.c : 포인터 변수
#include <stdio.h>

int main(void)
{
	int num1 = 100, num2 = 100;
	int* pnum;

	pnum = &num1;
	(*pnum) += 30;
	printf("Address of num1 : %p\n", &num1); // num1 의 주소값 반환
	printf("value of pnum : %p\n", pnum); // pnum 의 값 == num1의 주소값
	printf("Address of pnum : %p\n", &pnum); // pnum 의 주소 값 반환

	pnum = &num2; // pnum 의 값이 num2 의 주소로 초기화됨
	(*pnum) += 30;
	printf("Address of num2 : %p\n", &num2); // num2 의 주소값 반환
	printf("value of pnum : %p\n", pnum); // pnum 의 값 == num2의 주소값
	printf("Address of pnum : %p\n", &pnum); // pnum 의 주소 값 반환은 포인터 변수의 주소 값을 의미하고 이는 변경되지 않음

	printf("num1 : %d, num2 : %d\n", num1, num2); // 130 130 출력 

	return 0;
}