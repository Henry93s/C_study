// ���� ����� : ���Ͽ� �����͸� ���� �б�
#include <stdio.h>
int main() {
	// ���� �Է�
	FILE* fp = fopen("data.txt", "wt"); // w : ������ ������ ������ ����
	// r �̳� r+ ���� �б⳪ �б� �� ���� ����� ��� ������ ������ ���� !
	if (fp == NULL) {
		puts("���Ͽ��� ����!");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	fclose(fp); // ��Ʈ�� ����

	// ���� ���
	// ������ ���� ��Ʈ���� ����������Ƿ� fopen_s �Լ��� �����ϰ� fp ��Ʈ���� ������
	// fp ���� ��Ʈ�� ��� ����.
	fopen_s(fp, "data.txt", "rt");
	if (fp == NULL) {
		puts("���Ͽ��� ����!");
		return -1;
	}

	int ch, i;
	for (i = 0;i < 3;i++) {
		ch = fgetc(fp);
		printf("%c \n", ch);
	}
	fclose(fp); // ��Ʈ�� ����

	return 0;
}