#include <stdio.h>
// ��ũ�� ���� �� ������ ���ǵ� ��ũ�ε� ��� ������
// ������ ���������� �����ؼ� ������ �߿��ϳ� �����Ϸ��� ���� ������ �� ����
#define CIRCLE_AREA(R) (PRODUCT((R), (R))*PI)
#define PI 3.14
#define PRODUCT(X,Y) ((X)*(Y))



int main() {
	double rad = 2.1;
	printf("������ %g�� ���� ����: %g \n", rad, CIRCLE_AREA(rad));

	return 0;
}