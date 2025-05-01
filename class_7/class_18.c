// feof : ������ ���� ������ ��� 0 �� �ƴ� �� ��ȯ
// feof �� �̿��Ͽ� ������ �а� �����ϱ�
#include <stdio.h>
int main() {
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("dst.txt", "wt");
	int ch;

	if (src == NULL || des == NULL) {
		puts("���Ͽ��� ����!");
		return -1;
	}

	do { // src �ҽ� ���Ͽ��� ���� ������ ������ �������� ���� ������
		ch = fgetc(src); 
		fputc(ch, des); // des ���� ���Ͽ� ch �� �� ���
	} while (ch != EOF);

	if (feof(src) != 0) { // feof 0 �� �ƴ� �� ��ȯ -> ���� ���� �Ϸ�
		puts("���Ϻ��� �Ϸ�!");
	}
	else {
		puts("���Ϻ��� ����!");
	}

	fclose(src);
	fclose(des);

	return 0;
}