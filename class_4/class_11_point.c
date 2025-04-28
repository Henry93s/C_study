// class_11.c : 배열의 (첫 번째 요소) 값 주소를 parameter 로 넘기고 접근하기
// call by referrence
#include <stdio.h>
void ShowArrayElem(int* param, int len) { // 포인터 변수가 넘어오고 배열의 주소가 넘어옴
	int i;
	for (i = 0;i < len;i++) {
		printf("%d ", param[i]);
	}
	printf("\n");
}
void AddArrayElem(int* param, int len, int add) { // 포인터 변수가 parameter 로 넘어옴
	int i;
	for (i = 0;i < len;i++) {
		param[i] += add; // 포인터의 경우 주소이므로 call by referrence 의 개념이기 때문에 
		// 포인터를 통해 실제 값의 연산이 동작할 때 가리키는 배열의 실제 값도 변경된다 !
	}
}
int main() {
	int arr[3] = { 1,2,3 };
	AddArrayElem(arr, sizeof(arr) / sizeof(int), 1); // 배열의 모든 요소에 1 증가
	ShowArrayElem(arr, sizeof(arr) / sizeof(int)); // sizeof(arr) / sizeof(int) : 배열 arr 의 길이 측정(integer 배열의 길이)

	AddArrayElem(arr, sizeof(arr) / sizeof(int), 2); // 위 결과에 추가로 2 증가 
	ShowArrayElem(arr, sizeof(arr) / sizeof(int));

	AddArrayElem(arr, sizeof(arr) / sizeof(int), 3); // 위 결과에 추가로 3 증가
	ShowArrayElem(arr, sizeof(arr) / sizeof(int));

	return 0;
}
