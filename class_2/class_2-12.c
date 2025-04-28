// class_2-12.c : 두 좌표에서 직사각형의 넓이 구하기(교재 118page 문제 05-1 문제 1)
#include <stdio.h>
int main(void) {
	int x1, y1;
	int x2, y2;
	printf("(x1, y1) 좌표 1 입력: ");
	scanf_s("%d %d", &x1, &y1);
	printf("(x2, y2) 좌표 2 입력: ");
	scanf_s("%d %d", &x2, &y2);

	printf("%d\n", (x2 - x1) * (y2 - y1)); // 두 좌표에 따라 가로, 세로 길이를 계산하고 직사각형 넓이 공식 적용
	
	return 0;
}