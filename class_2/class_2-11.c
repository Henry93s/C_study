// class_2-11.c : �ƽ�Ű �ڵ� (A : 65)
#include <stdio.h>
int main(void) {
	char ch1 = 'A', ch2 = 65;
	int ch3 = 'Z', ch4 = 90;

	printf("%c %d \n", ch1, ch2); // ���� 'A' �� ���� 65 ���
	printf("%c %d \n", ch2, ch2); // ���� 65�� �ƽ�Ű �ڵ带 ����Ű�� 'A' �� ���� 65 ���
	printf("%c %d \n", ch3, ch3); // ���� 'Z' �� �ƽ�Ű �ڵ� 90 ���
	printf("%c %d \n", ch4, ch4); // ���� 90�� �ƽ�Ű �ڵ带 ����Ű�� 'Z' �� ���� 90 ���
	return 0;
}