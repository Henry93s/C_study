// ���� 1. 10���� ������ �Է¹޾Ƽ� Ȧ���� ¦���� �����Ͽ� ����ϴ� ���α׷� �ۼ�
#include <stdio.h>
int main() {
	int arr[10];
	int i;
	for (i = 0;i < 10;i++) { // 10���� ���� �Է�
		printf("�Է�: ");
		scanf_s("%d", &arr[i]);
	}

	printf("Ȧ�� ���: "); // Ȧ�� ��� 
	for (i = 0;i < 10;i++) {
		if (arr[i] % 2 != 0) { // arr[i] �� Ȧ�� �� ���� ��� (== if((num[i]&01) == 1))
			printf("%d ", arr[i]);
		}
	}
	printf("\n");

	printf("¦�� ���: "); // ¦�� ���
	for (i = 0;i < 10;i++) {
		if (arr[i] % 2 == 0) { // arr[i] �� ¦�� �� ���� ��� (== if((num[i]&01) == 0))
			printf("%d ", arr[i]);
		}
	}
	printf("\n");

	return 0;
}