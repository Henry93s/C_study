// class_13.c : ����ü : �ϳ� �̻��� ������ ��� ���ο� �ڷ����� �����ϴ� ����
#include <stdio.h>
#include <math.h>
struct point // ����ü ����
{
	int xpos;
	int ypos;
}; // ����ü ���� �� �����ݷ� �Ǽ� ����!
int main() { // �� �� ������ �Ÿ��� ����.
	struct point pos1, pos2; // ����ü ���� ����
	double distance;

	fputs("point1 pos: ", stdout);
	scanf_s("%d %d", &pos1.xpos, &pos1.ypos);

	fputs("point2 pos: ", stdout);
	scanf_s("%d %d", &pos2.xpos, &pos2.ypos);

	// �� �� ������ �Ÿ� ���ϱ� (��� ����. a, b �� �浹 ���� �Ǵ� ���� ���� ���� ���)
	distance = sqrt((double)(pos1.xpos - pos2.xpos) * (pos1.xpos - pos2.xpos) +
		(double)(pos1.ypos - pos2.ypos) * (pos1.ypos - pos2.ypos));
	printf("�� �� ������ �Ÿ��� %g �Դϴ�.\n", distance);

	return 0;
}