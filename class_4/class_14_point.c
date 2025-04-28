// class_14.c : call by value, call by reference 함수 구현
#include <stdio.h>
int SquareByValue(int n) { // call by value
	// : int n 으로 값을 복사하여 받고 main 함수에 return
	return n * n;
}
void SquareByReference(int* n) { // call by reference
	// : int* n 으로 변수의 주소를 받아서 값 변경 시 main 에서도 가리키는 실제 값이 변경됨;
	*n *= *n;
	return;
}

int main() {
	int n;
	scanf_s("%d", &n);

	printf("%d ", SquareByValue(n)); // return 된 n * n 출력
	SquareByReference(&n);
	printf("%d\n", n); // reference 함수에서 값이 변경된 n 출력(n * n)
	return 0;
}