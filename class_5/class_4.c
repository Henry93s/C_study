// class_4.c : 2���� �迭 ����
#include <stdio.h>
int main(void) {
	int arr2d[3][3];
	printf("%d \n", arr2d); // ��ü �迭�� ù ��°(0,0) �ּ�
	printf("%d \n", arr2d[0]); // �迭 1���� ù ��°(0,0) �ּ�
	printf("%d \n\n", &arr2d[0][0]); // �迭 (0,0)���� �ּ�

	printf("%d \n", arr2d[1]); // �迭 2���� ù ��°(1,0) �ּ�
	printf("%d \n\n", &arr2d[1][0]); // �迭 (1,0) ���� �ּ�

	printf("%d \n", arr2d[2]); // �迭 3���� ù ��°(2,0) �ּ�
	printf("%d \n\n", &arr2d[2][0]); // �迭 (2,0) ���� �ּ�

	printf("sizeof(arr2d): %d \n", sizeof(arr2d)); // ��ü �迭 �̹Ƿ� 36 byte
	printf("sizeof(arr2d[0]): %d \n", sizeof(arr2d[0])); // �������� ����̹Ƿ� ��� �� 12 byte
	printf("sizeof(arr2d[1]): %d \n", sizeof(arr2d[1]));
	printf("sizeof(arr2d[2]): %d \n", sizeof(arr2d[2]));

	return 0;
}
