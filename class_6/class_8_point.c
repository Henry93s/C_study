// class_8.c : ���ڿ��� ���ϴ� �Լ� strcmp, strncmp
// s1 �� �� ũ�� 1, s2 �� �� ũ�� -1, ������ 0
// strncmp : n���� ��
#include <stdio.h>
#include <string.h>
int main() {
	char str1[20];
	char str2[20];

	printf("���ڿ� �Է� 1: ");
	scanf_s("%s", str1);
	printf("���ڿ� �Է� 2: ");
	scanf_s("%s", str2);

	if (!strcmp(str1, str2)) { // strcmp : ���ڿ� ��
		printf("���� ���ڿ��Դϴ�.\n");
	}
	else {
		printf("�ٸ� ���ڿ��Դϴ�.\n");
		if (!strncmp(str1, str2, 3)) { // strncmp : ���ڿ� �� (n����)
			printf("���� 3���ڴ� �����ϴ�.\n");
		}
		else {
			printf("���� 3���ڴ� �ٸ��ϴ�.\n");
		}
	}

	return 0;
}