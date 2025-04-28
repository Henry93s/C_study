// class_2.c : 배열의 이름과 포인터의 관계
// 배열의 이름은 배열의 첫 번째 요소의 주소와 같다 !
#include <stdio.h>
int main(void) {
	int arr1[3] = { 1,2,3 };
	double arr2[3] = { 1.1,2.2,3.3 };

	printf("%d %g \n", *arr1, *arr2); // 1 1.1
	*arr1 += 100; // 배열의 이름이 가리키는 값은 첫 번째 값인 1
	*arr2 += 120.5; 
	printf("%d %g \n", arr1[0], arr2[0]); // 101 121.6
	return 0;
}
