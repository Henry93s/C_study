// 구조체 배열 접근
#include <stdio.h>
struct point { // 구조체 정의
	int xpos;
	int ypos;
};

int main() {
	// 구조체 변수 선언
	struct point arr[3];
	int i;

	for (i = 0; i < 3; i++) {
		printf("xpos, ypos 입력: ");
		scanf_s("%d %d", &arr[i].xpos, &arr[i].ypos); // 구조체 배열 요소의 주소 접근
	}

	for (i = 0; i < 3; i++) {
		printf("xpos: %d, ypos: %d\n", arr[i].xpos, arr[i].ypos); // 구조체 배열 접근
	}

	return 0;
}