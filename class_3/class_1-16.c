// class_1-16.c : �� �� �߿��� ���� ū �� �Ǵ� ���� ���� �� ���ϴ� �Լ�
#include <stdio.h>
int GetMax(int a, int b, int c) { // �� �� �� ���� ū �� ��ȯ �Լ� ���� �� �ʱ�ȭ
	int max;
	a > b ? (max = a) : (max = b); // ó�� �� �� ū ���� �ӽ÷� max �� ����
	max > c ? (max = max) : (max = c); // ������ ���� ���Ͽ� ���� max �� ����
	return max;
}
int GetMin(int a, int b, int c) { // �� �� �� ���� ���� �� ��ȯ �Լ� ���� �� �ʱ�ȭ
	int min;
	a < b ? (min = a) : (min = b); // ó�� �� �� ���� ���� �ӽ÷� min �� ����
	min < c ? (min = min) : (min = c); // ������ ���� ���Ͽ� ���� min �� ����
	return min;
}
int main() {
	int a, b, c;
	printf("�� ���� �Է� : ");
	scanf_s("%d %d %d", &a, &b, &c);
	printf("�� �� �� ���� ū �� : %d\n", GetMax(a, b, c));
	printf("�� �� �� ���� ���� �� : %d\n", GetMin(a, b, c));

	return 0;
}