// class_7.c ; ���ڿ��� ���̴� �Լ� strcat, strncat (_s)
// strncat : ���ڿ� ���� �� ���ڸ� �ڵ����� ����
#include <stdio.h>
#include <string.h>
int main() {
	char str1[20] = "first~";
	char str2[20] = "second";

	char str3[20] = "Simple num: ";
	char str4[20] = "1234567890";

	/**** case 1 ****/
	strcat_s(str1, sizeof(str1), str2); // str1�� str2�� ����
	puts(str1); // str1 ���

	/**** case 2 ****/
	strncat_s(str3, sizeof(str3), str4, 7); // str3�� str4�� ���� (���๮�� ����)
	puts(str3); // str3 ���

	return 0;
}