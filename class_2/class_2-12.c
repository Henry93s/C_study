// class_2-12.c : �� ��ǥ���� ���簢���� ���� ���ϱ�(���� 118page ���� 05-1 ���� 1)
#include <stdio.h>
int main(void) {
	int x1, y1;
	int x2, y2;
	printf("(x1, y1) ��ǥ 1 �Է�: ");
	scanf_s("%d %d", &x1, &y1);
	printf("(x2, y2) ��ǥ 2 �Է�: ");
	scanf_s("%d %d", &x2, &y2);

	printf("%d\n", (x2 - x1) * (y2 - y1)); // �� ��ǥ�� ���� ����, ���� ���̸� ����ϰ� ���簢�� ���� ���� ����
	
	return 0;
}