#include <stdio.h>
#include <string.h>

int main(void) {
	FILE* fp = fopen("text.txt", "rt"); // ���� ������ ���� �� �б� ��� �ʱ�ȭ
	int ret;
	char text;
	int aCnt = 0, pCnt = 0; // A �� �����ϴ� ���� �Ǵ� P �� �����ϴ� ���� ī��Ʈ ���� �ʱ�ȭ
	int isFirst = 1; // ���ڿ��� ù �������� �˸��� flag

	while (1) {
		ret = fgetc(fp); // fgetc �� int ret �� �ް� EOF �� �� �ݺ��� Ż��
		// ����(\n ����) ���ڴ� text �� ���� �ʰ� ���� ���ڸ� �������� ���ڿ��� ����
		// <-> fgets �� fgetc �� ��� ���� ���ڵ� ���ڿ��� �޾Ƽ� ���� ó���� �߰��� �ʿ��� !
		if (ret == EOF) {
			break;
		}
		if (isFirst && ret == 'A') { // ���ڿ� ù���ڰ� A �� �� acnt++
			aCnt++;
			isFirst = 0;
		}
		else if (isFirst && ret == 'P') { // ù���ڰ� P �� �� bcnt++
			pCnt++;
			isFirst = 0;
		}

		if (ret == ' ' || ret == '\n' || ret == '\t') { 
			// fgetc ���� ���� ���ڵ��� �� ��� ���� ���� ���ڴ�
			// ���ڿ��� ù ���ڷ� ó���ϵ��� �ϴ� ��Ʈ�� ���� ó��
			isFirst = 1;
		}
		printf("%c\n", ret); // Ȯ�ο� ���ڿ� ���
	}

	printf("A�� �����ϴ� �ܾ��� ��: %d\n", aCnt);
	printf("P�� �����ϴ� �ܾ��� ��: %d\n", pCnt);

	fclose(fp);

	return 0;
}