// class_9.c : �� �̿��� ��ȯ �Լ���
// atoi, atol, atof : ���ڿ��� ������ int / long / double ������ ��ȯ
// toupper, tolower : �빮�� / �ҹ��ڷ� ��ȯ
// isdigit, isalpha, isalnum : ���� / ���� / ����+���� ���� Ȯ��
// isupper, islower : �빮�� / �ҹ��� ���� Ȯ��
// isspace : ���� ���� ���� Ȯ��
#include <stdio.h>
#include <stdlib.h>
int main() {
	char str[20];
	printf("���� �Է�: ");
	scanf_s("%s", str, sizeof(str));
	// �߰� : ���ڿ��� �Է¹��� �� ������ ���ڰ� �� ���� \0 ���� ����� !!
	// -> sizeof(str) �� �ϰ� 20���ڸ� �Է��ص� �ִ� 19���ڱ����� ���� !
	printf("%d \n", atoi(str)); // ���ڿ��� ������ ��ȯ

	printf("�Ǽ� �Է�: ");
	scanf_s("%s", str, sizeof(str));
	printf("%g \n", atof(str)); // ���ڿ��� �Ǽ��� ��ȯ

	return 0;
}

