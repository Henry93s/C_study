// 구조체 변수와 포인터
// 구조체 포인터 변수에 접근 1, 2
#include <stdio.h>
struct point
{
	int xpos;
	int ypos;
};

int main() {
	struct point pos1 = { 1,2 };
	struct point pos2 = { 100,200 };
	struct point* pptr = &pos1; // 구조체 포인터 변수 선언 및 초기화

	(*pptr).xpos = 4; // 구조체 포인터 변수 접근 1.
	(*pptr).ypos = 5;
	printf("[%d, %d] \n", pptr->xpos, pptr->ypos); // 구조체 포인터 변수 접근 2.
	// 4, 5

	pptr = &pos2;
	pptr->xpos += 1;
	pptr->ypos += 2;
	printf("[%d, %d] \n", pptr->xpos, pptr->ypos);
	// 101, 102

	return 0;
}
