// ���� ��ġ �������� �̵� : fseek
// ������ 0, ���н� 0 �� �ƴ� ���� ��ȯ
#include <stdio.h>
int main() {
	// ���� ����
	FILE* fp = fopen("text.txt", "wt");
	fputs("123456789", fp);
	fclose(fp);

	// ���� ����
	fopen_s(fp, "text.txt", "rt");

	// seek_end test
	fseek(fp, -2, SEEK_END); // EOF ���� �������� 2ĭ �̵�
	putchar(fgetc(fp)); // 8

	// seek_set test
	fseek(fp, 2, SEEK_SET); // ù ��° ��ġ���� ���������� 2ĭ �̵�
	putchar(fgetc(fp)); // 3 // �� ��µǸ鼭 �ڵ����� ���� �����ʹ� 4 �� ����Ų��.

	// seek_cur test
	fseek(fp, 2, SEEK_CUR); // ���� ��ġ(4) ���� ���������� 2ĭ �̵�
	putchar(fgetc(fp)); // 6

	fclose(fp);
	return 0;
}