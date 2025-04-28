// class_15.c : �� ������ ����� ���� ���� swap �ϱ�
// num1�� num2 ��, num2 �� num3 ��, num3 �� num1 �� swap
#include <stdio.h>
void swap(int* num1, int* num2, int* num3) { // call by reference �Լ�
	int temp = *num1;
	*num1 = *num2;
	*num2 = *num3;
	*num3 = temp;
}
int main() {
	int num1 = 1, num2 = 2, num3 = 3;
	printf("%d %d %d\n", num1, num2, num3); // call by reference �Լ��� ���� ��
	// 1 2 3
	swap(&num1, &num2, &num3); // �ּҸ� �Ѱܼ� void �Լ����� reference �� ���� �� ���� ����
	printf("%d %d %d\n", num1, num2, num3); // 2 3 1

	return 0;
}