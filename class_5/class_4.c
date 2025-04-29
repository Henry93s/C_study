// class_4.c : 2차원 배열 접근
#include <stdio.h>
int main(void) {
	int arr2d[3][3];
	printf("%d \n", arr2d); // 전체 배열의 첫 번째(0,0) 주소
	printf("%d \n", arr2d[0]); // 배열 1행의 첫 번째(0,0) 주소
	printf("%d \n\n", &arr2d[0][0]); // 배열 (0,0)값의 주소

	printf("%d \n", arr2d[1]); // 배열 2행의 첫 번째(1,0) 주소
	printf("%d \n\n", &arr2d[1][0]); // 배열 (1,0) 값의 주소

	printf("%d \n", arr2d[2]); // 배열 3행의 첫 번째(2,0) 주소
	printf("%d \n\n", &arr2d[2][0]); // 배열 (2,0) 값의 주소

	printf("sizeof(arr2d): %d \n", sizeof(arr2d)); // 전체 배열 이므로 36 byte
	printf("sizeof(arr2d[0]): %d \n", sizeof(arr2d[0])); // 나머지는 행들이므로 모두 각 12 byte
	printf("sizeof(arr2d[1]): %d \n", sizeof(arr2d[1]));
	printf("sizeof(arr2d[2]): %d \n", sizeof(arr2d[2]));

	return 0;
}
