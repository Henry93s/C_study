// class_5.c : 포인터를 이용한 배열의 값 출력
#include <stdio.h>
int main(void) {
	int arr[3] = { 11,22,33 };
	int* ptr = arr;
	printf("%d %d %d \n", *ptr, *(ptr + 1), *(ptr + 2));
	// 포인터 연산을 통해 배열의 두 번째 요소 이상의 값을 출력할 때 반드시 괄호를 적용 !
	printf("%d ", *ptr); ptr++; // 11 출력하고 ptr 이 가리키는 주소 4 byte 증가
	printf("%d ", *ptr); ptr++; // 22 출력, ptr + 4 byte
	printf("%d ", *ptr); ptr--; // 33 출력, ptr - 4 byte
	printf("%d ", *ptr); ptr--; // 22 출력, ptr - 4 byte
	printf("%d ", *ptr); printf("\n"); // 11 출력
	return 0;
}
