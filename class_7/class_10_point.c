// ���� 23-1. 484p 
#include <stdio.h>
typedef struct point {
	int xpos;
	int ypos;
} Point;
void swap(Point* ptr1, Point* ptr2) { // ����ü ������ ������ �޴�
	// call by reference �Լ��� �����Ѵ�.
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
	printf("���� �� pos1: %d %d\n���� �� pos2: %d %d\n\n", pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);

	swap(&pos1, &pos2); // swap �Ű������� ����ü ������ ������ ���� �ϹǷ�
	// ����ü ������ �ּҸ� ����

	printf("���� �� pos1: %d %d\n���� �� pos2: %d %d\n", pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);

	return 0;
}