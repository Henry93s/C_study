// class_5.c : 포인터 연산(2차원)
#include <stdio.h>
int main() {
	int arr1[3][2];
	int arr2[2][3];

	printf("arr1: %p \n", arr1); // arr1 배열의 첫 번째 주소
	printf("arr1+1: %p \n", arr1 + 1); // arr1 배열 2행의 첫 번째 주소
	printf("arr1+2: %p \n", arr1 + 2); // arr1 배열 3행의 첫 번째 주소

	printf("arr2: %p \n", arr2); // arr2 배열의 첫 번째 주소
	printf("arr2+1: %p \n", arr2 + 1); // arr2 배열 2행의 첫 번째 주소

	return 0;
}
