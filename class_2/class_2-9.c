// class_2-9.c : �Ǽ� �ڷ��� double 
/*
	�Ҽ��� ���� ���е�: float(4 byte) < double(8 byte) < long double(12 byte)
*/
#include <stdio.h>
int main() {
	double rad;
	double area;
	printf("���� ������ �Է�: ");
	scanf_s("%lf", &rad); // double �� �����͸� �Է� ���� ��(scanf)�� ���Ĺ��� %lf ���
	// float �� �������� ��� ��� %f ���Ĺ��� ���
	area = rad * rad * 3.1415;
	printf("���� ����: %f \n", area); // double �� �����͸� ����� ��(printf) ���Ĺ��� %f �� %lf ���

	return 0;
}