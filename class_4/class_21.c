// class_21.c : ���� 2(349p)
#include <stdio.h>
int main() {
	int arr1[2][4] = {
		{1,2,3,4},
		{5,6,7,8}
	};
	int arr2[4][2]; // arr2 �� arr1 �� ���� �̿��Ͽ� �ʱ�ȭ�� �����ؾ� �Ѵ�.
	
	int i, j;
	for (i = 0;i < 4;i++) { // arr2 �� 1�� ������ �ʱ�ȭ
		arr2[i][0] = arr1[0][i];
	}
	for (i = 0;i < 4;i++) { // arr2 �� 2�� ������ �ʱ�ȭ
		for (j = 0;j < 2;j++) {
			arr2[i][1] = arr1[j][i];
		}
	}
	
	for (i = 0;i < 4;i++) {
		for (j = 0;j < 2;j++) {
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}