// class_1.c : ���� ������ ����
// dptr -> ptr -> num (-> : pointer)
#include <stdio.h>
int main() {
	double num = 3.14;
	double* ptr = &num;
	double** dptr = &ptr;
	double* ptr2;

	printf("%9p %9p \n", ptr, *dptr); // ��� num �ּ� ��
	printf("%9g %9g \n", num, **dptr); // ��� num ��
	ptr2 = *dptr; // num �ּҰ�
	*ptr2 = 10.99; 
	printf("%9g %9g \n", num, **dptr); // ��� num ��
	
	return 0;
}
