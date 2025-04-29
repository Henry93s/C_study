// class_10.c : 387 p 문제 1. 포인터 배열에 따른 배열 포인터 선언 및 초기화 문제
#include <stdio.h> 
int main() {
	int* arr1[5]; // 1차원 포인터 배열 
	int* arr2[3][5]; // 2차원 포인터 배열 (point!)

	int** ptr1 = arr1; // 문제 : ??? = arr1 이 컴파일되도록 배열 포인터를 선언
	// int *(*ptr1) = arr1 과 같음.
	int* (*ptr2)[5] = arr2; // 문제 : ??? = arr2 가 컴파일되도록 배열 포인터를 선언
	printf("%p %p\n", arr1, ptr1); // 위 문제 검증
	printf("%p %p\n", arr2, ptr2); // 아래 문제 검증
	
	return 0;
}