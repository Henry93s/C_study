// class_2.c : pointer swap ���� case
#include <stdio.h>
void SwapIntPtrFail(int* p1, int* p2) { 
	int* temp = p1; // ������ ������ �ּҸ� ��� �ּҸ� swap �ϸ� local function ������ swap �ȴ�.
	p1 = p2;
	p2 = temp;
	printf("After SwapIntPtrFail : %d %d \n", *p1, *p2); // local function ���ο����� �����
	// -> ����Ű�� ���� ���� swap �� �̷����� �ʾұ� ����.
}
void SwapIntPtrSuccess(int** p1, int** p2) { // �������� �ּҸ� ����
	// ���� �����͸� ����ؼ� swap �ϴ� ���
	int *temp = *p1; // ������ ���� ptr1 �� ptr2 �� ���� ������ �����ؾ� ��
	*p1 = *p2;
	*p2 = temp;
}
int main(void) {
	int num1 = 10, num2 = 20;
	int* ptr1, * ptr2;
	ptr1 = &num1, ptr2 = &num2;
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); // 10 20
	SwapIntPtrFail(ptr1, ptr2);
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); // 10 20
	SwapIntPtrSuccess(&ptr1, &ptr2); // ���� swap �Լ� parameter �� ���������� �̹Ƿ� ������ ������ �ּҸ� �ѱ�
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); // 20 10
	return 0;
}
