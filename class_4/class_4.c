// class_4.c : ������ �ּ� ����
#include <stdio.h>
int main(void) {
	int* ptr1 = 0x0010; // ������ �ּ� �� ����
	double* ptr2 = 0x0010;

	printf("%p %p \n", ptr1 + 1, ptr1 + 2); // 4 byte �� ���� (int)
	printf("%p %p \n", ptr2 + 1, ptr2 + 2); // 8 byte �� ���� (double)

	printf("%p %p \n", ptr1, ptr2); // ����� ������ �ּ� �� ���(64 bit pc �̹Ƿ� 16�ڸ� ���)
	ptr1++; // 4 byte ������Ŵ
	ptr2++; // 8 byte ������Ŵ
	printf("%p %p \n", ptr1, ptr2); // 4 byte ���̳��� �ּ� �� ���

	return 0;
}
