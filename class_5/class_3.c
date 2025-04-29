// class_3.c : pointer 배열의 pointer 형
#include <stdio.h>
int main() {
	int num1 = 10, num2 = 20, num3 = 30;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	int* ptr3 = &num3;

	int* ptrArr[] = { ptr1, ptr2, ptr3 }; // pointer 배열의 pointer 변수
	int** dptr = ptrArr; // pointer 배열의 주소(배열의 이름 = 첫 번째 주소) 를
	// 저장하는 dptr 이중 포인터 변수

	printf("%d %d %d\n", *(ptrArr[0]), *(ptrArr[1]), *(ptrArr[2])); // 10 20 30
	printf("%d %d %d\n", *(dptr[0]), *(dptr[1]), *(dptr[2])); // 10 20 30

	return 0;
}
