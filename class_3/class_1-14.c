// class_1-14.c : 숫자 비교 함수 작성
#include <stdio.h>
int NumberCompare(int num1, int num2); // main 함수 전에 함수를 선언만 하고 main 함수 후에 함수 내용을 작성해도 됨.
int main() {
	printf("3과 4중에서 큰 수는 %d 이다. \n", NumberCompare(3, 4));
	printf("7과 2중에서 큰 수는 %d 이다. \n", NumberCompare(7, 2));

	return 0;
}
int NumberCompare(int num1, int num2) { // main 함수에서 숫자 비교함수를 호출하기 전에 이미 선언은 되어 있어 에러가 발생하지 않음.
	if (num1 > num2) {
		return num1;
	}
	else {
		return num2;
	}
}