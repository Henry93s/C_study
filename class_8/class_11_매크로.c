// ��ũ�� �Լ� ����ó�� ����
#include <stdio.h>
#define SQUARE(X) X*X

int main() {
	int num = 2;
	printf("square of num: %d\n", SQUARE(num));
	printf("square of -5: %d\n", SQUARE(-5));
	printf("square of 2.5: %g \n", SQUARE(2.5));

	// ������ ��� ���
	printf("square of 3+2: %d\n", SQUARE(3 + 2)); // 3+2*3+2 �� �״�� ġȯ�Ǳ⸸ �ϱ� ������
	// 25 �� �����ߴ� ����� �ƴ� 3+(2*3)+2 �� 11�� ���
	// ��ũ�� ��ó����� �ܼ��� "ġȯ" �Ѵٴ� ����

	// ������ ��� -> ���� ����� ����
	printf("square of (3+2): %d\n", SQUARE((3 + 2))); // (3+2)*(3+2)
	// 25 ��µ�

	return 0;
}