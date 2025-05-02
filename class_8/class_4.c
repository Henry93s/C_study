// ���� ���� ��ġ �������� ��ġ �ľ� : ftell
#include <stdio.h>
int main() {
	long fpos;
	int i;

	// ���� ����
	FILE* fp = fopen("text.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);

	// ���� ����
	fopen_s(fp, "text.txt", "rt");

	for (i = 0;i < 4;i++) {
		putchar(fgetc(fp)); // 1
		fpos = ftell(fp); 
		fseek(fp, -1, SEEK_END); // -
		putchar(fgetc(fp)); 
		fseek(fp, fpos, SEEK_SET);
	fclose(fp);

	return 0;
}