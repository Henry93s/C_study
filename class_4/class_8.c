// class_8.c : ������ ������ �̷��� �迭 -> ������ �迭
#include <stdio.h>
int main() {
	int num1 = 10, num2 = 20, num3 = 30;
	int* arr[3] = { &num1, &num2, &num3 }; // int �� ������ �迭 ���� �� �ʱ�ȭ

	printf("%d \n", *arr[0]); // 10 : arr[0] �� &num1 �̹Ƿ� * �� �ٿ��� ����Ű�� �� ��� ����
	printf("%d \n", *arr[1]); // 20
	printf("%d \n", *arr[2]); // 30

	return 0;
}
