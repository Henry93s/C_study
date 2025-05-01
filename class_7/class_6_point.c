// typedef 로 선언한 구조체 변수를 parameter 로 넘기기
#include <stdio.h>
typedef struct point {
	int xpos;
	int ypos;
} Point; // typedef 로 구조체를 정의와 동시에 또다른 이름인 Point 부여

void ShowPosition(Point pos) { 
	// 함수의 파라미터에 넣을 때도 typedef 로 정의한 이름이 있을 경우
	// defined 된 구조체 자료형의 새 이름만 넣으면 됨.
	printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

Point GetCurrentPosition() {
	Point cen; // struct point cen;
	printf("Input current pos: ");
	scanf_s("%d %d", &cen.xpos, &cen.ypos);

	return cen;
}

int main() {
	Point curPos = GetCurrentPosition();
	ShowPosition(curPos);

	return 0;
}