// class_2-10.c : 실수 자료형 double 2
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
	printf("Area of circle : %.20f\n", area_f); // %.20f 소수점 6자리까지 유효 및 20자리까지 출력
	printf("Area of circle : %.20lf\n", area_d); // %.20lf 소수점 15자리까지 유효 및 20자리까지 출력

	return 0;
}