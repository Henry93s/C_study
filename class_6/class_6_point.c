// class_6.c : ���ڿ��� �����ϴ� �Լ� strcpy (strcpy_s, strncpy)
// -> strcpy �� ���� �����÷ο찡 �߻��� �� ����
// -> strcpy_s �� ����Ͽ� ���� �����÷ο츦 ����
// strncpy -> ����� �迭�� ���̸� �Ѿ�� �ʴ� ���� ������ ���� ����
#include <stdio.h>
#include <string.h>
int main() {
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	/**** case 1 ****/
	strcpy_s(str2, sizeof(str2), str1); // str2�� str1�� ����
	puts(str2); // str2 ���

	/**** case 2 ERROR ****/ 
	/*
	strncpy_s(str3, sizeof(str3), str1, sizeof(str3)); // str3�� str1�� ����
	puts(str3); // str3 ���
	*/

	/**** case 3 ****/
	strncpy_s(str3, sizeof(str3), str1, sizeof(str3) - 1); // str3�� str1�� ����
	str3[sizeof(str3) - 1] = '\0'; // str3�� �������� NULL ���� �߰�
	puts(str3); // str3 ���

	return 0;
}