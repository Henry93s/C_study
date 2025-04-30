// class_13.c : 구조체 : 하나 이상의 변수를 묶어서 새로운 자료형을 정의하는 도구
#include <stdio.h>
#include <math.h>
struct point // 구조체 정의
{
	int xpos;
	int ypos;
}; // 구조체 정의 후 세미콜론 실수 주의!
int main() { // 두 점 사이의 거리를 구함.
	struct point pos1, pos2; // 구조체 변수 선언
	double distance;

	fputs("point1 pos: ", stdout);
	scanf_s("%d %d", &pos1.xpos, &pos1.ypos);

	fputs("point2 pos: ", stdout);
	scanf_s("%d %d", &pos2.xpos, &pos2.ypos);

	// 두 점 사이의 거리 구하기 (사용 예제. a, b 의 충돌 여부 판단 같은 곳에 많이 사용)
	distance = sqrt((double)(pos1.xpos - pos2.xpos) * (pos1.xpos - pos2.xpos) +
		(double)(pos1.ypos - pos2.ypos) * (pos1.ypos - pos2.ypos));
	printf("두 점 사이의 거리는 %g 입니다.\n", distance);

	return 0;
}