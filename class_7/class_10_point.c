// 문제 23-1. 484p 
#include <stdio.h>
typedef struct point {
	int xpos;
	int ypos;
} Point;
void swap(Point* ptr1, Point* ptr2) { // 구조체 포인터 변수를 받는
	// call by reference 함수로 진행한다.
	int temp;
	temp = ptr1->xpos;
	ptr1->xpos = ptr2->xpos;
	ptr2->xpos = temp;

	temp = ptr1->ypos;
	ptr1->ypos = ptr2->ypos;
	ptr2->ypos = temp;

	return;
}
int main() {
	Point pos1 = { 2,4 };
	Point pos2 = { 5,7 };
	printf("변경 전 pos1: %d %d\n변경 전 pos2: %d %d\n\n", pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);

	swap(&pos1, &pos2); // swap 매개변수로 구조체 포인터 변수가 들어가야 하므로
	// 구조체 변수의 주소를 삽입

	printf("변경 후 pos1: %d %d\n변경 후 pos2: %d %d\n", pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);

	return 0;
}