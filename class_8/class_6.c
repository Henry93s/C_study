// 동적할당 예제
#include <stdio.h>
#include <stdlib.h>
int main() {
	int* ptr1 = (int*)malloc(sizeof(int)); // 힙 메모리 영역에 4 바이트 할당
	int* ptr2 = (int*)malloc(sizeof(int) * 7); // 4 * 7 = 28 바이트 할당

	int i;
	*ptr1 = 20;
	for (i = 0;i < 7;i++) {
		ptr2[i] = i + 1;
	}

	printf("%d \n", *ptr1);
	for (i = 0;i < 7;i++) {
		printf("%d ", ptr2[i]);
	}

	free(ptr1); // 가능한 heap 영역에 있는 메모리를 해제하는 것이 좋다.
	free(ptr2);

	return 0;
}