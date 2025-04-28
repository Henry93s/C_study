// class_21.c : 문제 2(349p)
#include <stdio.h>
int main() {
	int arr1[2][4] = {
		{1,2,3,4},
		{5,6,7,8}
	};
	int arr2[4][2]; // arr2 는 arr1 의 값을 이용하여 초기화를 진행해야 한다.
	
	int i, j;
	for (i = 0;i < 4;i++) { // arr2 의 1열 데이터 초기화
		arr2[i][0] = arr1[0][i];
	}
	for (i = 0;i < 4;i++) { // arr2 의 2열 데이터 초기화
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