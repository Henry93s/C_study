// ����ü ���� call by reference ����
#include <stdio.h>
typedef struct point {
	int xpos; // ����ü �ɹ�
	int ypos;
} Point;

void OrgSymTrans(Point* ptr) { // ����ü�� �ּҷ� �޾Ƽ� �����ϹǷ� ����ü ������ �����̰� -> �� �����.
	ptr->xpos = (ptr->xpos) * -1;
	ptr->ypos = (ptr->ypos) * -1;
}

void ShowPosition(Point pos) {
	// �Լ��� �Ķ���Ϳ� ���� ���� typedef �� ������ �̸��� ���� ���
	// defined �� ����ü �ڷ����� �� �̸��� ������ ��.
	printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

int main() {
	Point pos = { 10,20 }; // ����ü ����
	OrgSymTrans(&pos);
	ShowPosition(pos);
	OrgSymTrans(&pos);
	ShowPosition(pos);

	return 0;
}