#include <stdio.h>
#include <stdlib.h>
typedef struct complex {
	double a;
	double b;
}complex;

double add(double a, double b) { // ���Ҽ� ���� ����
	return a + b;
}
double mul(int type, complex a, complex b) { // ���Ҽ� ���� ����
	if (type == 0) {
		return a.a * b.a - a.b * b.b;
	}
	else {
		return a.a * b.b - a.b * b.a;
	}
	
}

int main() {
	complex* num = (complex*)malloc(sizeof(complex) * 2);

	int i;
	for (i = 0;i < 2;i++) {
		printf("���Ҽ� �Է� %d [�Ǽ� ���]: ", i + 1);
		scanf_s("%lf %lf", &(num + i)->a, &(num + i)->b);
	}

	printf("���� ���] �Ǽ�: %lf, ���: %lf\n", \
		add(num[0].a, num[1].a), add(num[0].b, num[1].b));
	printf("���� ���] �Ǽ�: %lf, ���: %lf\n", \
		mul(0, num[0], num[1]), mul(1, num[0], num[1]));

	return 0;
}