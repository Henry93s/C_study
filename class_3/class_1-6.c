// class_1-6.c : if ~ else ���ǹ�
#include <stdio.h>
int main() {
	int num;
	printf("���� �Է�: ");
	scanf_s("%d", &num);

	// if ~ else ���ǹ��� ������ ���� ������ �� ���� ����� ���� �� �����.
	if (num < 0) {
		printf("�Է� ���� 0���� �۴�. \n");
	}
	else { 
		printf("�Է� ���� 0���� ���� �ʴ�. \n");
	}

	return 0;
}