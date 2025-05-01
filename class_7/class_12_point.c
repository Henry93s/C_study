// 23-2 ����, 488p
#include <stdio.h>
typedef struct point {
	int xpos;
	int ypos;
} Point;

typedef struct rectangle { 
	Point x; // ù ��° �� ��ǥ (��ø ����ü ����)
	Point y; // �� ��° �� ��ǥ (��ø ����ü ����)
} Rectangle;

int width(Rectangle* rectangle) { 
	// �Ű� ������ ����ü �ּұ� ������ �Լ� ���ο��� ��� �� ����ü ������ ����
	// ó�� -> �� ����Ѵ� !
	int x, y; // x : ���� ����, y : ���� ����
	x = (rectangle->y).xpos - (rectangle->x).xpos; 
	// ��ø ����ü ���� �� ��ȣ �ʼ� !
	y = (rectangle->y).ypos - (rectangle->x).ypos;
	return x * y;
}

int main() {
	Rectangle rect;
	
	scanf_s("%d %d", &rect.x.xpos, &rect.x.ypos);
	scanf_s("%d %d", &rect.y.xpos, &rect.y.ypos);

	printf("%d\n", width(&rect)); // ����ü�� �ּҸ� �ѱ�

	return 0;
}
