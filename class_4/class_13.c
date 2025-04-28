// class_13.c : call by reference 함수 동작
#include <stdio.h>
void Swap(int* ptr1, int* ptr2) { // 변수의 주소를 parameter 로 받아서 
	// 이후 함수 내부에서 가리키는 값의 변경이 이뤄짐
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
int main() {
	int num1 = 10;
	int num2 = 20;
	printf("num1 num2: %d %d \n", num1, num2); // 10 20
	Swap(&num1, &num2); // call by reference 함수를 통해 swap 을 진행하므로
	// 실제 값이 바뀜
	printf("num1 num2: %d %d \n", num1, num2); // 20 10

	return 0;
}
