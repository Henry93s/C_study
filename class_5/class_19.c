// 423p ���� 21-1. ���� ��ҹ��� ��ȯ
#include <stdio.h>
int main() {
	char a = getchar();

	if (a >= 97 && a <= 122) { // �ҹ��� a �ƽ�Ű�ڵ� 97 ~ 122
		putchar(a - 32);
	}
	else if(a >= 65 && a <= 90){ // �빮�� �ƽ�Ű�ڵ� 65 ~ 90
		putchar(a + 32);
	}
	else {
		printf("INPUT ERROR !\n");
	}

	return 0;
}