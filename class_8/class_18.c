// 26-1 ���� 1. 576p
#include <stdio.h>
#define SUM(x, y, z) (x)+(y)+(z)
#define MUL(x, y, z) (x)*(y)*(z)

int main() {
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);

	printf("���� : %d\n", SUM(a, b, c));
	printf("����: %d\n", MUL(a, b, c));

	return 0;
}