// ���� 2 551p
#include <stdio.h>
#include <stdlib.h>
int main() {
	int size = 5;
	int* arr = (int*)malloc(sizeof(int) * size);

	int i = 0;
	int n;
	while (1) {
		scanf_s("%d", &n);
		if (n == -1) {
			i--;
			break;
		}
		else {
			if (i == size) {
				size += 5;
				// realoc : Ȯ���� ũ�Ⱑ �ƴ� ��ü ũ�⸦ ���ϴ� ����
				// �޸� ������ ��ĥ ��� Ȯ���̵ǰ�, �ٸ� ��� ���Ҵ��� �� !!
				arr = (int*)realloc(arr, sizeof(int) * size); 
			}
			arr[i++] = n;
		}
	}

	// �߰� ���� �����ϱ�
	// ��������
	int j, k;
	int temp; 
	for (j = 0;j < i;j++) { // (���꿡�� + 1 �ε��� �������� ����
		// ������ i ���� �����͸� �����ϹǷ� ������ �ε��� i ����
		for (k = 0;k < i;k++) { // �� ��� ������ !!!
			if (arr[k + 1] < arr[k]) { // ������ i ���� �����͸� �����ϹǷ� ������ �ε��� i ����
				temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
			}
		}
	}
	for (j = 0;j <= i;j++) { // ������ i ���� �����͸� �����ϹǷ�
		printf("%d ", arr[j]);
	}

	return 0;
}