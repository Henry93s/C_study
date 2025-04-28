// class_4.c : 포인터 주소 연산
#include <stdio.h>
int main(void) {
	int* ptr1 = 0x0010; // 임의의 주소 값 저장
	double* ptr2 = 0x0010;

	printf("%p %p \n", ptr1 + 1, ptr1 + 2); // 4 byte 씩 증가 (int)
	printf("%p %p \n", ptr2 + 1, ptr2 + 2); // 8 byte 씩 증가 (double)

	printf("%p %p \n", ptr1, ptr2); // 현재는 동일한 주소 값 출력(64 bit pc 이므로 16자리 출력)
	ptr1++; // 4 byte 증가시킴
	ptr2++; // 8 byte 증가시킴
	printf("%p %p \n", ptr1, ptr2); // 4 byte 차이나는 주소 값 출력

	return 0;
}
