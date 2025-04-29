// �Լ� �����͸� �Ű������� Ȱ���Ͽ� ���� ����� �ǽ� ����
#include <stdio.h>
float add(int n1, int n2) {
	return n1 + n2;
}
float minus(int n1, int n2) {
	return n1 - n2;
}
float mul(int n1, int n2) {
	return n1 * n2;
}
float div(int n1, int n2) {
	return n1 / n2;
}
// �Ű������� �Լ� ������ �߰�
float calculate(int n1, int n2, float (*func)(int n1, int n2)) {
	return func(n1, n2);
}
int main(void) {
	int n1, n2;
	char op; // ���� ��ȣ
	float result = 0;

	printf("���� ��ȣ �Է� : ");
	scanf_s("%c", &op, 1);
	printf("n1 n2 �Է� : ");
	scanf_s("%d %d", &n1, &n2);

	if (op == '+') {
		result = calculate(n1, n2, add);
	}
	else if (op == '-') {
		result = calculate(n1, n2, minus);
	}
	else if (op == '*') {
		result = calculate(n1, n2, mul);
	}
	else if (op == '/') {
		result = calculate(n1, n2, div);
	}

	printf("��� ��� : %.2f", result);
	
	return 0;
}