// class_2-4.c : scanf �Լ��� ����
/*
	scanf("%d", &val);
	-> 10���� �������� �Է� �޾Ƽ� ���� val�� ����
*/
#include <stdio.h>
int main(void) {
	int result;
	int num1, num2;

	printf("����: one: ");
	scanf_s("%d", &num1); // ù ��° ���� �Է� �� ���� num1 �� ����
	// build �� scanf ��� secure coding ���� scanf_s ��� �����
	/*
		CERT C : C ��� ���� ����� ������ ���� ��ť�� �ڵ� ǥ��
		CERT C ǥ�ؿ� ���Ͽ� scanf ��� �� ������ ������ �߻���
	*/
	printf("����: two: ");
	scanf_s("%d", &num2); // �� ��° ���� �Է� �� ���� num2 �� ����

	result = num1 + num2;
	printf("%d + %d = %d \n", num1, num2, result);
	return 0;
}