// class_3.c : fflush -> ��¹��۸� ���� �Լ�
#include <stdio.h>
void ClearLineFromReadBuffer() { // ���ۿ��� '\n' �� ���� ������ ���ڸ� �о����
	while (getchar() != '\n');
}
int main() {
	char perID[7];
	char name[10];

	fputs("�ֹι�ȣ �� 6�ڸ� �Է�: ", stdout);
	fgets(perID, sizeof(perID), stdin); // �Է¹��� �� enter Ű���� �Էµ�
	// ���� -> ���ۿ��� ���๮�ڸ� �о�帮�� �Լ� ���
	ClearLineFromReadBuffer(); // �Է� ���� �����

	fputs("�̸� �Է�: ", stdout); 
	fgets(name, sizeof(name), stdin); // ���ۿ� �����ִ� \n �� �Էµ�

	printf("�ֹι�ȣ: %s\n", perID);
	printf("�̸�: %s\n", name);

	return 0;
}

