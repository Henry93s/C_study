// 구조체 변수 대상으로 가능한 연산
// 대입연산, & 연산(주소 값 반환 연산), 구조체 변수 크기를 반환하는 sizeof 연산
#include <stdio.h>
typedef struct point {
	int xpos; // 맴버
	int ypos;
}Point;

int main() {
	Point pos1 = { 1,2 };
	Point pos2;

	pos2 = pos1; // 구조체 맴버간 복사가 진행됨 (대입연산)
	printf("크기: %d \n", sizeof(pos1)); // sizeof 연산
	printf("[%d, %d] \n", pos1.xpos, pos1.ypos);
	printf("크기: %d \n", sizeof(pos2));
	printf("[%d, %d] \n", pos2.xpos, pos2.ypos);

	return 0;
}