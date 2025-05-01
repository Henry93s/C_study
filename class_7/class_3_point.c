// 구조체와 구조체 포인터 변수를 활용한 single linkedlist(연결리스트)
#include <stdio.h>
struct point {
	int xpos;
	int ypos;
	struct point* ptr; // 구조체 내부에 같은 구조체의 포인터 변수 생성
};

int main() {
	struct point pos1 = { 1,1 }; // pos3 까지 각각의 구조체 변수 생성
	struct point pos2 = { 2,2 };
	struct point pos3 = { 3,3 };

	pos1.ptr = &pos2;
	pos2.ptr = &pos3;
	pos3.ptr = &pos1;
	// pos 1 -> pos 2 -> pos 3 -> pos 1 구조의 single 연결리스트 
	// ==> 구조체 포인터 변수로 다른 구조체 맴버에 접근 !

	printf("점의 연결관계... \n");
	printf("[%d, %d]와(과) [%d, %d] 연결 \n"
		, pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos); // 1 1 2 2
	printf("[%d, %d]와(과) [%d, %d] 연결 \n"
		, pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos); // 2 2 3 3
	printf("[%d, %d]와(과) [%d, %d] 연결 \n"
		, pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos); // 3 3 1 1

	return 0;
}