// ������ ������ ����ü�� ����� �����ϱ�
// linkedlist, tree ��� �߿��ϰ� Ȱ��� !
#include <stdio.h>
struct point {
	int xpos;
	int ypos;
};
struct circle {
	double radius;
	struct point* center; // ����ü ���ο� �ٸ� ����ü ������ ���� ����
	// ���� ����ü ������ ������ ���� ����
};
int main() {
	struct point cen = { 2, 7 };
	double rad = 5.5;

	struct circle ring = { rad, &cen };
	printf("���� ������; %g\n", ring.radius);
	// ����ü ������ ����ü ������ ������ �����ϱ�
	printf("���� �߽�: [%d, %d]\n", (ring.center)->xpos, ring.center->ypos);

	return 0;
}