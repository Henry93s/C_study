/*
typedef struct div { // ����ü typedef ����
	int quotient;
	int remainder;
}Div;
*/
#include "class_1_����ü�����������.h" // ����ü�� ���ǵ� ��������� include !
#ifndef __class_1_����ü�Լ������������_h__ // ���Ǻ� ��ũ�θ� �̿��� ��������� �ߺ������� ����
#define __class_1_����ü�Լ������������_h__
#endif // !__"class_1_����ü�Լ������������_h"__
Div IntDiv(int num1, int num2) { // �ܺ� ���Ϸ� ����ü�� Ȱ���� �Լ� ����
	Div dval;
	dval.quotient = num1 / num2;
	dval.remainder = num1 % num2;
	return dval;
}