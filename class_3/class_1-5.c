// class_1-5.c : if ���ǹ� 2
#include <stdio.h>
int main() {
	int opt;
	double num1, num2;
	double result;

	printf("1.���� 2.���� 3.���� 4.������ \n");
	printf("����? ");
	scanf_s("%d", &opt);
	printf("�� ���� �Ǽ� �Է�: ");
	scanf_s("%lf %lf", &num1, &num2); // �Ǽ��� �Է� ���� ���� ���Ĺ��ڴ� %lf ��� (double)

	// �ݺ����� if ���� if���鿡 ������ ���� ������ ���� ��� switch ~ case ���� Ȱ���ϴ� ���� �� ������ ����
	if (opt == 1) {
		result = num1 + num2;
	}
	if (opt == 2) {
		result = num1 - num2;
	}
	if (opt == 3) {
		result = num1 * num2;
	}
	if (opt == 4) {
		result = num1 / num2;
	}
	printf("���: %f \n", result);
	return 0;
	
	/* �� if ���� if ~ else if ~ else ������ ����
		if(opt==1){
			result = num1 + num2;}
		else if(opt==2){
			result = num1 - num2;}
		else if(opt==3){
			result = num1 * num2;}
		else {
			result = num1 / num2;}
	*/
}