// class_12.c : 388p ¹®Á¦ 3.
#include <stdio.h>
void ComplexFuncOne(int** arr1, int* (*arr2)[5]) {}
void ComplexFuncTwo(int** (*arr3), int*** (*arr4)[4]) {}
int main() {
	int* arr1[3];
	int* arr2[3][5];
	int** arr3[5];
	int*** arr4[3][4];

	ComplexFuncOne(arr1, arr2);
	ComplexFuncTwo(arr3, arr4);

	return 0;
}