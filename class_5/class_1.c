// class_1.c : 이중 포인터 이해
// dptr -> ptr -> num (-> : pointer)
#include <stdio.h>
int main() {
	double num = 3.14;
	double* ptr = &num;
	double** dptr = &ptr;
	double* ptr2;

	printf("%9p %9p \n", ptr, *dptr); // 모두 num 주소 값
	printf("%9g %9g \n", num, **dptr); // 모두 num 값
	ptr2 = *dptr; // num 주소값
	*ptr2 = 10.99; 
	printf("%9g %9g \n", num, **dptr); // 모두 num 값
	
	return 0;
}
