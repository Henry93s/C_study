// 445 p 21-2 ���� 2. scanf_s ���� ���ڿ� ���� ���� ���๮�ڰ� ���� x, 
// gets �� fgets �� ���ڿ� ���� ���� ���๮�ڰ� ���Ե�
// -> ���๮�� �ʿ� �� ������ ���ڸ� '\0' �� ���ڷ� ���� ����
#include <stdio.h>
#include <string.h>
int main() {
	char str1[20];
	char str2[20];
	char str3[40];

	fgets(str1, 20, stdin);
	str1[strlen(str1) - 1] = '\0'; // ���ο� �ִ� ���� ���ڸ� ������ �ι��ڷ� ���� 
	fgets(str2, 20, stdin);
	str2[strlen(str2) - 1] = '\0';

	strncpy_s(str3, 40, str1, 20); // str3 �� str1 ���ڿ� ����
	strncat_s(str3, 20, str2, 20); // str3 �� str2 ���ڿ� ���̱�

	printf("%s\n", str3);
}