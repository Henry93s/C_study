// 문제 2 551p
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
				// realoc : 확장할 크기가 아닌 전체 크기를 정하는 개념
				// 메모리 영역이 겹칠 경우 확장이되고, 다를 경우 재할당이 됨 !!
				arr = (int*)realloc(arr, sizeof(int) * size); 
			}
			arr[i++] = n;
		}
	}

	// 추가 문제 정렬하기
	// 버블정렬
	int j, k;
	int temp; 
	for (j = 0;j < i;j++) { // (연산에서 + 1 인덱스 연산으로 인해
		// 위에서 i 까지 데이터를 저장하므로 마지막 인덱스 i 제외
		for (k = 0;k < i;k++) { // 비교 대상 셀렉터 !!!
			if (arr[k + 1] < arr[k]) { // 위에서 i 까지 데이터를 저장하므로 마지막 인덱스 i 제외
				temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
			}
		}
	}
	for (j = 0;j <= i;j++) { // 위에서 i 까지 데이터를 저장하므로
		printf("%d ", arr[j]);
	}

	return 0;
}