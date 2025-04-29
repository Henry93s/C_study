// class_11.c : 387 p 문제 2. 이중포인터 매개변수 선언 (메인에서 주어진 함수에 따라 정의할 함수의 파라미터 작성하기)
#include <stdio.h>
void SimpleFuncOne(int* arr1, int* arr2) {}
void SimpleFuncTwo(int (*arr3)[4], int (*arr4)[4]) {}
int main() {
	int arr1[3];
	int arr2[4];
	int arr3[3][4];
	int arr4[2][4];

	SimpleFuncOne(arr1, arr2); // 배열의 이름(배열의 첫 요소 주소) 가 넘어가므로 파라미터로 포인터 변수
	SimpleFuncTwo(arr3, arr4); // 배열의 이름(2차원 배열의 첫 요소 주소) 가 넘어가므로 파라미터로 (*a)[4] 로 포인터 변수
}