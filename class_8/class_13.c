// ��ũ�� �Լ��� ����
#include <stdio.h>
// ��ũ�η� �������� ��
#define DIFF_ABS(X,Y) ((x)>(y)?(x)-(y):(y)-(x))

// �Լ��� �������� ��
double diff_abs(int x, int y) {
	double result = x > y ? (x - y) : (y - x);
	return result;
}

int main() {
	printf("�� ���� ��: %g \n", diff_abs(5, 7));
	// printf("�� ���� ��: %g \n", DIFF_ABS(1.8, -1.4)); // error
	// => ��ũ�� �Լ� �Ű����� X �� �ƴ϶� x �� ġȯ��
	return 0;
}