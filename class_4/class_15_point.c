// class_15.c : 세 변수에 저장된 값을 서로 swap 하기
// num1은 num2 로, num2 는 num3 로, num3 은 num1 로 swap
#include <stdio.h>
void swap(int* num1, int* num2, int* num3) { // call by reference 함수
	int temp = *num1;
	*num1 = *num2;
	*num2 = *num3;
	*num3 = temp;
}
int main() {
	int num1 = 1, num2 = 2, num3 = 3;
	printf("%d %d %d\n", num1, num2, num3); // call by reference 함수로 변경 전
	// 1 2 3
	swap(&num1, &num2, &num3); // 주소를 넘겨서 void 함수에서 reference 를 통한 값 변경 진행
	printf("%d %d %d\n", num1, num2, num3); // 2 3 1

	return 0;
}