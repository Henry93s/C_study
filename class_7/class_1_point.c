// ����ü ������ ������
// ����ü ������ ������ ���� 1, 2
#include <stdio.h>
struct point
{
	int xpos;
	int ypos;
};

int main() {
	struct point pos1 = { 1,2 };
	struct point pos2 = { 100,200 };
	struct point* pptr = &pos1; // ����ü ������ ���� ���� �� �ʱ�ȭ

	(*pptr).xpos = 4; // ����ü ������ ���� ���� 1.
	(*pptr).ypos = 5;
	printf("[%d, %d] \n", pptr->xpos, pptr->ypos); // ����ü ������ ���� ���� 2.
	// 4, 5

	pptr = &pos2;
	pptr->xpos += 1;
	pptr->ypos += 2;
	printf("[%d, %d] \n", pptr->xpos, pptr->ypos);
	// 101, 102

	return 0;
}
