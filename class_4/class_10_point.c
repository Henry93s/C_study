// class_10.c : 배열을 함수의 인자로 전달하는 방식
// -> 배열의 주소(이름) 를 전달하여 첫 번째 요소부터 확인할 수 있도록 한다.
#include <stdio.h>
void ShowArrayElem(int* param, int len) { // param 이라는 포인터 변수가 넘어옴
	// 즉 배열의 주소가 넘어옴 -> call by referrence
	// -> 배열의 모든 값을 컨트롤 및 변경 적용할 수 있다.
	int i;
	for (i = 0;i < len;i++) {
		printf("%d ", param[i]);
	}
	printf("\n");
}
int main() {
	int arr1[3] = { 1,2,3 };
	int arr2[5] = { 4,5,6,7,8 };
	ShowArrayElem(arr1, sizeof(arr1) / sizeof(int)); 
	// sizeof(arr1) / sizeof(int) 로 배열의 길이를 알아낼 수 있다.
	// arr1의배열크기 / 4 byte = 3
	// 1 2 3 출력
	ShowArrayElem(arr2, sizeof(arr2) / sizeof(int));
	// 4 5 6 7 8 출력

	return 0;
}