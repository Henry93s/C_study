#include <stdio.h>

/*
typedef struct div {
	int quotient;
	int remainder;
} Div; // Div ����ü ���� : �����Ϸ��� ���� ������ �������� �����ϹǷ�
//						    Div �� ���� ���� �� ���Ǵ� Div �� �ʿ�� �ϴ� ��� ���Ͽ� �����ؾ���
// => �� ��� ��� ���Ͽ��� ����ü�� ������ �� ���� �����ϵ��� ������ �� ���� !
*/

#include "class_1_����ü�����������.h" // ����ü�� ���ǵ� ��������� include !
#ifndef __class_1_����ü�Լ������������_h__ // ���Ǻ� ��ũ�θ� �̿��� ��������� �ߺ������� ����
#define __class_1_����ü�Լ������������_h__ // . ��� _ ��ȣ �� �糡�� __ ��� !
#endif // !__class_1_����ü�Լ������������_h__

extern Div IntDiv(int num1, int num2); // �ܺο��� ���ǵ� ����ü�� Ȱ���� �Լ��� �����

int main() {
	Div val = IntDiv(5, 2);
	printf("��: %d \n", val.quotient);
	printf("������: %d \n", val.remainder);

	return 0;
}