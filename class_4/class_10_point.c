// class_10.c : �迭�� �Լ��� ���ڷ� �����ϴ� ���
// -> �迭�� �ּ�(�̸�) �� �����Ͽ� ù ��° ��Һ��� Ȯ���� �� �ֵ��� �Ѵ�.
#include <stdio.h>
void ShowArrayElem(int* param, int len) { // param �̶�� ������ ������ �Ѿ��
	// �� �迭�� �ּҰ� �Ѿ�� -> call by referrence
	// -> �迭�� ��� ���� ��Ʈ�� �� ���� ������ �� �ִ�.
	int i;
	for (i = 0;i < len;i++) {
		printf("%d ", param[i]);
	}
	printf("\n");
}
int main() {
	int arr1[3] = { 1,2,3 };
	int arr2[5] = { 4,5,6,7,8 };
	ShowArrayElem(arr1, sizeof(arr1) / sizeof(int)); 
	// sizeof(arr1) / sizeof(int) �� �迭�� ���̸� �˾Ƴ� �� �ִ�.
	// arr1�ǹ迭ũ�� / 4 byte = 3
	// 1 2 3 ���
	ShowArrayElem(arr2, sizeof(arr2) / sizeof(int));
	// 4 5 6 7 8 ���

	return 0;
}