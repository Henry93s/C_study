// class_1-19.c : 배열
#include <stdio.h>
int main() {
	int arr[5];
	int sum = 0, i;
	arr[0] = 10, arr[1] = 20, arr[2] = 30, arr[3] = 40, arr[4] = 50;
	// 위 arr[5] 를 선언과 동시에 초기화 할 수 있음
	// -> int arr[5] = {10, 20, 30, 40, 50};
	// = int arr[] = {10, 20, 30, 40, 50}; : 컴파일러에서 자동으로 배열 길이 5 로 초기화됨
	// int arr[5] = {10, 20}; : 배열의 길이는 5로 초기화되지만 나머지 값은 0 으로 초기화 된다.

	for (i = 0;i < 5;i++) { // 배열의 첫 번째 인덱스는 반드시 0 부터 시작하여야 함!
		sum += arr[i];
	}

	printf("배열요소에 저장된 값의 합: %d\n", sum);
	return 0;
}
