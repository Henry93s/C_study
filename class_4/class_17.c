// class_17.c : 2���� �迭 ����
#include <stdio.h>
int main() {
	int arr1[3][4];
	int arr2[7][9];
	printf("����3, ����4: %d\n", sizeof(arr1)); // 3 * 4 * 4 byte = 48
	printf("����7, ����9: %d\n", sizeof(arr2)); // 7 * 9 * 4 byte = 252
	
	return 0;
}
