// class_1-18.c : static ���� ���� 
// static ���� : ���� ������ ���� ������ �� ���� Ư���� ��� ������ ����
// 1. ���� ����(local) Ư�� : �ش� �Լ��� ��ȯ�ϸ� ���� �Ҹ��.
// 2. ���� ����(global) Ư�� : ���α׷� ���� �ñ��� �޸� ������ ���� ��� ������
// 3. ����� �Լ� �������� ��� �����ϴ�(�߰�ȣ ����) <- ���� ���� o, ���� ���� x
#include <stdio.h>
void SimpleFunc(void) {
	static int num1 = 0; // �ʱ�ȭ���� ������ 0 �ʱ�ȭ(static ���� ����)
	int num2 = 0; // �ʱ�ȭ���� ������ ������ �� �ʱ�ȭ(��������)
	num1++, num2++;
	printf("static: %d, local: %d\n", num1, num2);
}
int main() {
	int i;
	for (i = 0;i < 3;i++) {
		SimpleFunc();
	}
	// i=0 : static : 1, local : 1
	// i=1 : static : 2, local : 1
	// i=2 : static : 3, local : 1

	return 0;
}