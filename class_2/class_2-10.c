// class_2-10.c : �Ǽ� �ڷ��� double 2
#include <stdio.h>
#include <math.h>

int main(void)
{
	double rad;
	float area_f;
	double area_d;

	printf("input the size of radius : ");
	scanf("%lf", &rad);

	area_f = rad * rad * M_PI;
	area_d = rad * rad * M_PI;
	printf("Area of circle : %.20f\n", area_f); // %.20f �Ҽ��� 6�ڸ����� ��ȿ �� 20�ڸ����� ���
	printf("Area of circle : %.20lf\n", area_d); // %.20lf �Ҽ��� 15�ڸ����� ��ȿ �� 20�ڸ����� ���

	return 0;
}