// ����ü ���� ������� ������ ����
// ���Կ���, & ����(�ּ� �� ��ȯ ����), ����ü ���� ũ�⸦ ��ȯ�ϴ� sizeof ����
#include <stdio.h>
typedef struct point {
	int xpos; // �ɹ�
	int ypos;
}Point;

int main() {
	Point pos1 = { 1,2 };
	Point pos2;

	pos2 = pos1; // ����ü �ɹ��� ���簡 ����� (���Կ���)
	printf("ũ��: %d \n", sizeof(pos1)); // sizeof ����
	printf("[%d, %d] \n", pos1.xpos, pos1.ypos);
	printf("ũ��: %d \n", sizeof(pos2));
	printf("[%d, %d] \n", pos2.xpos, pos2.ypos);

	return 0;
}