// 26-1 ���� 2 576p
#include <stdio.h>
#define PI 3.14
#define AREA(r) (r)*(r)*(PI)

int main() {
	int r;
	scanf_s("%d", &r);

	printf("�� ����: %g\n", AREA(r)); // ����� 3.14 �� ���߱� ������ double �� ��ȯ

	return 0;
}