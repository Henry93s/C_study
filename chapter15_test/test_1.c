// 문제 1. 10개의 정수를 입력받아서 홀수와 짝수를 구분하여 출력하는 프로그램 작성
#include <stdio.h>
int main() {
	int arr[10];
	int i;
	for (i = 0;i < 10;i++) { // 10개의 정수 입력
		printf("입력: ");
		scanf_s("%d", &arr[i]);
	}

	printf("홀수 출력: "); // 홀수 출력 
	for (i = 0;i < 10;i++) {
		if (arr[i] % 2 != 0) { // arr[i] 가 홀수 일 때만 출력 (== if((num[i]&01) == 1))
			printf("%d ", arr[i]);
		}
	}
	printf("\n");

	printf("짝수 출력: "); // 짝수 출력
	for (i = 0;i < 10;i++) {
		if (arr[i] % 2 == 0) { // arr[i] 가 짝수 일 때만 출력 (== if((num[i]&01) == 0))
			printf("%d ", arr[i]);
		}
	}
	printf("\n");

	return 0;
}