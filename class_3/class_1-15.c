// class_1-15.c : �Լ� �� �Լ� ȣ��
#include <stdio.h>
int AbsoCompare(int num1, int num2); // ������ ���ϰ� ������ ū ���� ��ȯ�ϴ� �Լ�
int GetAbsoValue(int num); // ������ ���ϴ� �Լ�
int main() {
	int num1, num2;
	printf("�� ���� ���� �Է�: ");
	scanf_s("%d %d", &num1, &num2);
	printf("%d�� %d�� ������ ū ����: %d \n", num1, num2, AbsoCompare(num1, num2));
	
	return 0;
}
int AbsoCompare(int num1, int num2) {
	if (GetAbsoValue(num1) > GetAbsoValue(num2)) {
		return num1;
	}
	else {
		return num2;
	}
}
int GetAbsoValue(int num) {
	if (num < 0) {
		return num * (-1);
	}
	else {
		return num;
	}
}