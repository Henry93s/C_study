// class_1-20.c : 배열 선언 및 초기화
#include <stdio.h>
int main() {
	int arr1[5] = { 1,2,3,4,5 }; // 배열 선언과 동시에 초기화
	int arr2[] = { 1,2,3,4,5,6,7 }; // [] 이므로 배열의 길이는 7로 자동 초기화
	int arr3[5] = { 1,2 }; // 배열의 길이는 5 로 초기화, 1,2 외 나머지 값은 0 으로 초기화
	int ar1Len, ar2Len, ar3Len, i;

	printf("배열 arr1의 크기: %d\n", sizeof(arr1)); // 4 byte * 배열의 길이 5 = 20
	printf("배열 arr2의 크기: %d\n", sizeof(arr2)); // 4 * 7 = 28
	printf("배열 arr3의 크기: %d\n", sizeof(arr3)); // 4 * 5 = 20

	ar1Len = sizeof(arr1) / sizeof(int); // 20 / 4 = 5 배열의 길이 계산
	ar2Len = sizeof(arr2) / sizeof(int); // 7
	ar3Len = sizeof(arr3) / sizeof(int); // 5
	
	for (i = 0;i < ar1Len;i++) { // 배열 전체 값 출력은 for 반복문을 통해 주로 활용함
		printf("%d ", arr1[i]); // 1 2 3 4 5
	}
	printf("\n");

	for (i = 0;i < ar2Len;i++) {
		printf("%d ", arr2[i]); // 1 2 3 4 5 6 7
	}
	printf("\n");

	for (i = 0;i < ar3Len;i++) { 
		printf("%d ", arr3[i]); // 1 2 0 0 0
	}
	printf("\n");

	return 0;
}