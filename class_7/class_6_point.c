// typedef �� ������ ����ü ������ parameter �� �ѱ��
#include <stdio.h>
typedef struct point {
	int xpos;
	int ypos;
} Point; // typedef �� ����ü�� ���ǿ� ���ÿ� �Ǵٸ� �̸��� Point �ο�

void ShowPosition(Point pos) { 
	// �Լ��� �Ķ���Ϳ� ���� ���� typedef �� ������ �̸��� ���� ���
	// defined �� ����ü �ڷ����� �� �̸��� ������ ��.
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