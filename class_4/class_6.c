// class_6.c : �����͸� �̿��� �迭�� ����, 299 p 13-1.����
#include <stdio.h>
int main() {
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = arr; // ������ ���� ���� �� �ʱ�ȭ

	for (int i = 0;i < 5;i++) {
		*(ptr + i) += 2; // �迭�� ������ ������ ���� ���� 2�� ���� ��Ŵ
		printf("%d ", *(ptr + i)); // 3 4 5 6 7 ���
	}
	printf("\n");
	return 0;
}
