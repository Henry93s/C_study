// class_16 : XOR 교체 알고리즘 -> temp 변수 필요없이 교체 대상 값들로만 변경 가능
#include <stdio.h>
void swap(int* x, int* y) { // temp 변수 없이 교체 대상 값들로만 XOR 교체 알고리즘을 통해 변경 가능
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