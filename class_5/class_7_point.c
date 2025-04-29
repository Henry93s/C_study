// class_7.c : 포인터 배열과 배열 포인터
#include <stdio.h>
int main() {
	int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
	int arr2d[2][4] = { 1,2,3,4,5,6,7,8 };
	int i, j;

	int* whoA[4] = { &num1, &num2, &num3, &num4 }; // 포인터 배열
	int (*whoB)[4] = arr2d; // 배열 포인터(배열을 가리키는 포인터
	// [4] 처럼 배열은 행 또는 열 둘 중 하나에는 반드시 길이를 명시해야함 !!!

	printf("%d %d %d %d \n", *whoA[0], *whoA[1], *whoA[2], *whoA[3]);
	for (i = 0;i < 2;i++) {
		for (j = 0;j < 4;j++) {
			printf("%d ", whoB[i][j]);
		}
		printf("\n");
	}
	return 0;
}