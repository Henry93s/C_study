// class_1-12.c : �Լ� �����ϱ�(���� func)
#include <stdio.h>
static int Add(int num1, int num2) { // Add �Լ� ����
	return num1 + num2;
}
int main() {
	int result;
	result = Add(3, 4); // 3+ 4
	printf("�������1: %d\n", result);

	result = Add(5, 8); // 5 + 8
	printf("�������2: %d\n", result);

	return 0;
}