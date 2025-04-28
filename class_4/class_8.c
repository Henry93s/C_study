// class_8.c : 포인터 변수로 이뤄진 배열 -> 포인터 배열
#include <stdio.h>
int main() {
	int num1 = 10, num2 = 20, num3 = 30;
	int* arr[3] = { &num1, &num2, &num3 }; // int 형 포인터 배열 선언 및 초기화

	printf("%d \n", *arr[0]); // 10 : arr[0] 은 &num1 이므로 * 을 붙여야 가리키는 값 출력 가능
	printf("%d \n", *arr[1]); // 20
	printf("%d \n", *arr[2]); // 30

	return 0;
}
