 // class_1.c : 포인터와 배열의 관계
#include <stdio.h>
int main(void) {
	int arr[3] = { 0, 1, 2 };
	printf("배열의 이름: %p \n", arr);
	printf("첫 번째 요소: %p \n", &arr[0]); // 배열의 이름과 동일한 값
	// -> 즉, 배열의 이름과 배열의 첫 번째 값의 주소는 동일함.
	// + 추가로 배열의 주소는 변경이 불가능하다.
		// ex : arr = &arr[i]; <- 컴파일 에러 발생 문장(주소 변경을 시도했기 때문)
	printf("두 번째 요소: %p \n", &arr[1]); // 첫 번째 요소 주소와 4 byte 차이(integer 배열이므로)
	printf("세 번째 요소: %p \n", &arr[2]);

	printf("첫 번째 요소가 가리키는 값: %d\n", *(arr + 0));
	// *(arr + 0) == arr[0]
	return 0;
}
