// class_16 : XOR ��ü �˰��� -> temp ���� �ʿ���� ��ü ��� ����θ� ���� ����
#include <stdio.h>
void swap(int* x, int* y) { // temp ���� ���� ��ü ��� ����θ� XOR ��ü �˰����� ���� ���� ����
	if (x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
	return;
}
int main() {
	int num1 = 1, num2 = 2;
	printf("%d %d\n", num1, num2); // 1 2
	swap(&num1, &num2);
	printf("%d %d\n", num1, num2); // 2 1

	return 0;
}