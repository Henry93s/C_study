// class_7.c : ���ڿ� �迭������ ������ Ȱ��
#include <stdio.h>
int main() {
	char str1[] = "My String"; // ���� ������ ���ڿ�
	char* str2 = "Your String"; // ��� ������ ���ڿ�

	printf("%s %s \n", str1, str2);

	str2 = "Our String";
	printf("%s %s \n", str1, str2); // Your -> Our

	str1[0] = 'X'; // ���� ���� ���ڿ��̹Ƿ� ���� ����
	printf("%s %s \n", str1, str2);
	str2[0] = 'X'; // ��� ���� ���ڿ��̹Ƿ� ���� �Ұ�
	printf("%s %s \n", str1, str2); // str2 �� ������� ������, �ٷ� ������ ���� �õ� �� ���� �߻����� ���α׷� ����
	// ��, ������ ���� printf ���� x

	str2 = str1; // str2 �ּҸ� ���� ������ ���ڿ��� �ּҷ� ���������Ƿ�
	printf("%s %s \n", str1, str2); // �� ���� ��µȴ�.

	return 0;
}