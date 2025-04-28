// class_6.c : 포인터를 이용한 배열의 접근, 299 p 13-1.문제
#include <stdio.h>
int main() {
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = arr; // 포인터 변수 선언 및 초기화

	for (int i = 0;i < 5;i++) {
		*(ptr + i) += 2; // 배열을 포인터 연산을 통해 값을 2씩 증가 시킴
		printf("%d ", *(ptr + i)); // 3 4 5 6 7 출력
	}
	printf("\n");
	return 0;
}
