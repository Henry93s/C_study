// class_5.c : ������ ����(2����)
#include <stdio.h>
int main() {
	int arr1[3][2];
	int arr2[2][3];

	printf("arr1: %p \n", arr1); // arr1 �迭�� ù ��° �ּ�
	printf("arr1+1: %p \n", arr1 + 1); // arr1 �迭 2���� ù ��° �ּ�
	printf("arr1+2: %p \n", arr1 + 2); // arr1 �迭 3���� ù ��° �ּ�

	printf("arr2: %p \n", arr2); // arr2 �迭�� ù ��° �ּ�
	printf("arr2+1: %p \n", arr2 + 1); // arr2 �迭 2���� ù ��° �ּ�

	return 0;
}
