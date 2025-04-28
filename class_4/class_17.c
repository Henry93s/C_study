// class_17.c : 2차원 배열 선언
#include <stdio.h>
int main() {
	int arr1[3][4];
	int arr2[7][9];
	printf("세로3, 가로4: %d\n", sizeof(arr1)); // 3 * 4 * 4 byte = 48
	printf("세로7, 가로9: %d\n", sizeof(arr2)); // 7 * 9 * 4 byte = 252
	
	return 0;
}
