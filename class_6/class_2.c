// class_2.c : fgets ���ڿ� �� ��� �Լ�
#include <stdio.h>
int main() {
	char str[7];
	int i;

	for (i = 0;i < 3;i++) {
		fgets(str, sizeof(str), stdin); 
		// gets �� ���������� ���� ���۰� ������ ����(���� �����÷ο�)�� �߻��� �� �־ 
		// scanf �� ���� gets_s �� ���(visual studio), linux �� gets ����
		printf("Read %d: %s\n", i + 1, str);
	}

	return 0;
}