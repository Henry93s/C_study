// class_5.c : �����͸� �̿��� �迭�� �� ���
#include <stdio.h>
int main(void) {
	int arr[3] = { 11,22,33 };
	int* ptr = arr;
	printf("%d %d %d \n", *ptr, *(ptr + 1), *(ptr + 2));
	// ������ ������ ���� �迭�� �� ��° ��� �̻��� ���� ����� �� �ݵ�� ��ȣ�� ���� !
	printf("%d ", *ptr); ptr++; // 11 ����ϰ� ptr �� ����Ű�� �ּ� 4 byte ����
	printf("%d ", *ptr); ptr++; // 22 ���, ptr + 4 byte
	printf("%d ", *ptr); ptr--; // 33 ���, ptr - 4 byte
	printf("%d ", *ptr); ptr--; // 22 ���, ptr - 4 byte
	printf("%d ", *ptr); printf("\n"); // 11 ���
	return 0;
}
