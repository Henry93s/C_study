// class_1-22.c : 포인터
#include <stdio.h>
int main() {
	int num1 = 100, num2 = 100;
	int* pnum;

	pnum = &num1;	// 포인터 pnum이 num1을 가리킴
	(*pnum) += 30;	// num1+=30; 과 동일

	pnum = &num2;	//포인터 pnum이 num2를 가리킴
	(*pnum) -= 30;	// num2-=30; 과 동일

	printf("num1:%d, num2:%d \n", num1, num2);	// 130 70
	return 0;
}