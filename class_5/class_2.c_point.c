// class_2.c : pointer swap 실패 case
#include <stdio.h>
void SwapIntPtrFail(int* p1, int* p2) { 
	int* temp = p1; // 포인터 변수에 주소를 담고 주소를 swap 하면 local function 에서만 swap 된다.
	p1 = p2;
	p2 = temp;
	printf("After SwapIntPtrFail : %d %d \n", *p1, *p2); // local function 내부에서만 변경됨
	// -> 가리키는 값에 대한 swap 이 이뤄지지 않았기 때문.
}
void SwapIntPtrSuccess(int** p1, int** p2) { // 포인터의 주소를 받음
	// 이중 포인터를 사용해서 swap 하는 경우
	int *temp = *p1; // 포인터 변수 ptr1 과 ptr2 에 직접 접근이 가능해야 함
	*p1 = *p2;
	*p2 = temp;
}
int main(void) {
	int num1 = 10, num2 = 20;
	int* ptr1, * ptr2;
	ptr1 = &num1, ptr2 = &num2;
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); // 10 20
	SwapIntPtrFail(ptr1, ptr2);
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); // 10 20
	SwapIntPtrSuccess(&ptr1, &ptr2); // 성공 swap 함수 parameter 가 이중포인터 이므로 포인터 변수의 주소를 넘김
	printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); // 20 10
	return 0;
}
