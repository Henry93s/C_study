// class_1-23.c : ������ ����
#include <stdio.h>

int main(void)
{
	int num1 = 100, num2 = 100;
	int* pnum;

	pnum = &num1;
	(*pnum) += 30;
	printf("Address of num1 : %p\n", &num1); // num1 �� �ּҰ� ��ȯ
	printf("value of pnum : %p\n", pnum); // pnum �� �� == num1�� �ּҰ�
	printf("Address of pnum : %p\n", &pnum); // pnum �� �ּ� �� ��ȯ

	pnum = &num2; // pnum �� ���� num2 �� �ּҷ� �ʱ�ȭ��
	(*pnum) += 30;
	printf("Address of num2 : %p\n", &num2); // num2 �� �ּҰ� ��ȯ
	printf("value of pnum : %p\n", pnum); // pnum �� �� == num2�� �ּҰ�
	printf("Address of pnum : %p\n", &pnum); // pnum �� �ּ� �� ��ȯ�� ������ ������ �ּ� ���� �ǹ��ϰ� �̴� ������� ����

	printf("num1 : %d, num2 : %d\n", num1, num2); // 130 130 ��� 

	return 0;
}