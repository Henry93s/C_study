// class_1-14.c : ���� �� �Լ� �ۼ�
#include <stdio.h>
int NumberCompare(int num1, int num2); // main �Լ� ���� �Լ��� ���� �ϰ� main �Լ� �Ŀ� �Լ� ������ �ۼ��ص� ��.
int main() {
	printf("3�� 4�߿��� ū ���� %d �̴�. \n", NumberCompare(3, 4));
	printf("7�� 2�߿��� ū ���� %d �̴�. \n", NumberCompare(7, 2));

	return 0;
}
int NumberCompare(int num1, int num2) { // main �Լ����� ���� ���Լ��� ȣ���ϱ� ���� �̹� ������ �Ǿ� �־� ������ �߻����� ����.
	if (num1 > num2) {
		return num1;
	}
	else {
		return num2;
	}
}