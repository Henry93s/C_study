// class_2-16.c : ���� ǥ���
#include <stdio.h>
int main() {
	double d1 = 1.23e-3; // 0.00123
	double d2 = 1.23e-4; // 0.000123
	double d3 = 1.23e-5; // 0.0000123
	double d4 = 1.23e-6; // 0.00000123

	printf("%g \n", d1); // %f ��Ÿ�� ��� -> 0.00123
	printf("%g \n", d2); // %f ��Ÿ�� ��� -> 0.000123
	printf("%g \n", d3); // %e ��Ÿ�� ��� -> 1.23e-05
	printf("%g \n", d4); // %e ��Ÿ�� ��� -> 1.23e-06

	return 0;
}