// class_1-4.c : ������

#include <stdio.h>

int main() {
	int num1 = 3;	// num1 ���� ���� �� �ʱ�ȭ
	int num2 = 4;	// num2 ���� ���� �� �ʱ�ȭ
	int result = num1 + num2; // result ���� ���� �� ���� ��� ���� 

	printf("���� ���: %d \n", result);
	printf("%d+%d=%d \n", num1, num2, result);
	printf("%d��(��) %d�� ���� %d�Դϴ�.\n", num1, num2, result);

	return 0;
}