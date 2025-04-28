// class_14.c : call by value, call by reference �Լ� ����
#include <stdio.h>
int SquareByValue(int n) { // call by value
	// : int n ���� ���� �����Ͽ� �ް� main �Լ��� return
	return n * n;
}
void SquareByReference(int* n) { // call by reference
	// : int* n ���� ������ �ּҸ� �޾Ƽ� �� ���� �� main ������ ����Ű�� ���� ���� �����;
	*n *= *n;
	return;
}

int main() {
	int n;
	scanf_s("%d", &n);

	printf("%d ", SquareByValue(n)); // return �� n * n ���
	SquareByReference(&n);
	printf("%d\n", n); // reference �Լ����� ���� ����� n ���(n * n)
	return 0;
}