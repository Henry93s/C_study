// class_11.c : �迭�� (ù ��° ���) �� �ּҸ� parameter �� �ѱ�� �����ϱ�
// call by referrence
#include <stdio.h>
void ShowArrayElem(int* param, int len) { // ������ ������ �Ѿ���� �迭�� �ּҰ� �Ѿ��
	int i;
	for (i = 0;i < len;i++) {
		printf("%d ", param[i]);
	}
	printf("\n");
}
void AddArrayElem(int* param, int len, int add) { // ������ ������ parameter �� �Ѿ��
	int i;
	for (i = 0;i < len;i++) {
		param[i] += add; // �������� ��� �ּ��̹Ƿ� call by referrence �� �����̱� ������ 
		// �����͸� ���� ���� ���� ������ ������ �� ����Ű�� �迭�� ���� ���� ����ȴ� !
	}
}
int main() {
	int arr[3] = { 1,2,3 };
	AddArrayElem(arr, sizeof(arr) / sizeof(int), 1); // �迭�� ��� ��ҿ� 1 ����
	ShowArrayElem(arr, sizeof(arr) / sizeof(int)); // sizeof(arr) / sizeof(int) : �迭 arr �� ���� ����(integer �迭�� ����)

	AddArrayElem(arr, sizeof(arr) / sizeof(int), 2); // �� ����� �߰��� 2 ���� 
	ShowArrayElem(arr, sizeof(arr) / sizeof(int));

	AddArrayElem(arr, sizeof(arr) / sizeof(int), 3); // �� ����� �߰��� 3 ����
	ShowArrayElem(arr, sizeof(arr) / sizeof(int));

	return 0;
}
