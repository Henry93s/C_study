// class_6.c: ���ڿ��� ���̸� ��ȯ�ϴ� �Լ� strlen (string.h)
#include <stdio.h>
#include <string.h>
void RemoveBSN(char str[]) {
	int len = strlen(str);
	str[len - 1] = '\0'; // ���ڿ� ������ ���ڸ� '\0' ���� ���� �����Ͽ� ���๮�� ����
}
int main() {
	char str[100];
	printf("���ڿ� �Է�: ");
	fgets(str, sizeof(str), stdin);
	// fgets �� ���๮�ڵ� �����Ͽ� ������ (scanf_s�� ���๮�� ���� �ȵ� -> ���ۿ� �������� !)
	printf("����: %d, ����: %s\n", strlen(str), str);

	RemoveBSN(str); // ���๮�� ����
	printf("����: %d, ����: %s\n", strlen(str), str);
	
	return 0;
}