// class_14.c : �Լ� ������ ���
#include <stdio.h>
void SimpleAdder(int n1, int n2) {
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
}
void ShowString(char* str) {
	printf("%s \n", str);
}
int main() {
	const char* str = "Function Pointer";
	int num1 = 10, num2 = 20;

	void (*fptr1)(int, int) = SimpleAdder; // �Լ� ������
	void (*fptr2)(char*) = ShowString;

	// �Լ� ������ ������ ���� ȣ��
	fptr1(num1, num2);
	fptr2(str);

	return 0;
}