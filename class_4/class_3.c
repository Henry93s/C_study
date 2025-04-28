// class_3.c : 포인터를 배열의 이름처럼 사용할 수 있는 추가 예제
#include <stdio.h>
int main(void) {
	int arr[3] = { 15,25,35 };
	int* ptr = &arr[0]; // int* ptr=arr; 과 동일한 문장

	printf("%d %d \n", ptr[0], arr[0]); // 15 15
	// 배열도 포인터 처럼 표현 *(arr + 0)
	// 포인터도 배열처럼 표현 ptr[0] 과 같이 사용이 가능하다
	printf("%d %d \n", ptr[1], arr[1]); // 25 25
	printf("%d %d \n", ptr[2], arr[2]); // 35 35
	printf("%d %d \n", *ptr, *arr); // 15 15 -> *ptr == *arr == ptr[0] == arr[0] 같음
	// 배열의 이름은 배열의 첫 번째 값의 주소와 같다 !!!
	// 배열의 인덱스 접근 방식 보다 포인터의 주소 접근 방식이 더 빠르다.
	return 0;
}
