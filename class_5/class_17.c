// ���� �Է� / ��� �Լ�
#include <stdio.h>
int main(void) {
	int ch1, ch2;
	ch1 = getchar(); // ���� �Է�
	ch2 = fgetc(stdin); // enter Ű �Է�

	putchar(ch1); // ���� ���
	fputc(ch2, stdout); // enter Ű ���

	return 0;
}