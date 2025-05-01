// 구조체 변수 call by reference 전달
#include <stdio.h>
typedef struct point {
	int xpos; // 구조체 맴버
	int ypos;
} Point;

void OrgSymTrans(Point* ptr) { // 구조체를 주소로 받아서 수행하므로 구조체 포인터 변수이고 -> 를 사용함.
	ptr->xpos = (ptr->xpos) * -1;
	ptr->ypos = (ptr->ypos) * -1;
}

void ShowPosition(Point pos) {
	// 함수의 파라미터에 넣을 때도 typedef 로 정의한 이름이 있을 경우
	// defined 된 구조체 자료형의 새 이름만 넣으면 됨.
	printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

int main() {
	Point pos = { 10,20 }; // 구조체 변수
	OrgSymTrans(&pos);
	ShowPosition(pos);
	OrgSymTrans(&pos);
	ShowPosition(pos);

	return 0;
}