/*
	���� 6. ���α׷� ����ڷκ��� ��(second) �� �Է� ���� ��, �̸� ��, ��, �� �� ���·� ����ϴ� ���α׷� �ۼ�.
*/
#include <stdio.h>
int main(void) {
	int sec; // second �� ���� ����
	printf("��(second) �Է�: ");
	scanf_s("%d", &sec); // second �� ���� �Է� ����

	int h, m, s; // �ð�, ��, �� ���
	h = sec / 3600;
	m = sec % 3600 / 60;
	s = sec % 3600 % 60;
	printf("h: %d, m: %d, s: %d\n", h, m, s); // �ð� ���� ���� ����Ѵ�.

	return 0;
}