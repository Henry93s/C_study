// class_2-2.c : ����, �� ������
#include <stdio.h>
int main(void) {
	int num1 = 10;
	int num2 = 12;
	int result1, result2, result3;

	result1 = (num1 == 10 && num2 == 12); // num1 �� 10 �̰� num2 �� 12 �� �ʱ�ȭ �Ǿ����Ƿ� �� -> 1
	result2 = (num1 < 12 || num2 > 12); // num1 �� 12 ���� �����Ƿ� or �������� ���� �� -> 1
	result3 = (!num1); // 0 �� �ƴ� ���� ��� ������ ����ϹǷ� �̿� ���� ! not ������ ���� -> 0

	printf("result1: %d \n", result1); // 1
	printf("result2: %d \n", result2); // 1
	printf("result3: %d \n", result3); // 0

	return 0;
}
