// class_11.c : 387 p ���� 2. ���������� �Ű����� ���� (���ο��� �־��� �Լ��� ���� ������ �Լ��� �Ķ���� �ۼ��ϱ�)
#include <stdio.h>
void SimpleFuncOne(int* arr1, int* arr2) {}
void SimpleFuncTwo(int (*arr3)[4], int (*arr4)[4]) {}
int main() {
	int arr1[3];
	int arr2[4];
	int arr3[3][4];
	int arr4[2][4];

	SimpleFuncOne(arr1, arr2); // �迭�� �̸�(�迭�� ù ��� �ּ�) �� �Ѿ�Ƿ� �Ķ���ͷ� ������ ����
	SimpleFuncTwo(arr3, arr4); // �迭�� �̸�(2���� �迭�� ù ��� �ּ�) �� �Ѿ�Ƿ� �Ķ���ͷ� (*a)[4] �� ������ ����
}