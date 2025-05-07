#include <stdio.h>
#include <string.h>

int main(void) {
	FILE* fp = fopen("text.txt", "rt"); // ���� ������ ���� �� �б� ��� �ʱ�ȭ
	int ret;
	char text[50]; // ���ڿ��� ������� text �迭
	int aCnt = 0, pCnt = 0; // A �� �����ϴ� ���� �Ǵ� P �� �����ϴ� ���� ī��Ʈ ���� �ʱ�ȭ
	while (1) {
		ret = fscanf_s(fp, "%s", text, 50); // fscanf �� int ret �� �ް� EOF �� �� �ݺ��� Ż��
		// ����(\n ����) ���ڴ� text �� ���� �ʰ� ���� ���ڸ� �������� ���ڿ��� ����
		// <-> fgets �� ��� ���� ���ڵ� ���ڿ��� �޾Ƽ� ���� ó���� �߰��� �ʿ��� !
		if (ret == EOF) {
			break;
		}
		if (text[0] == 'A') { // ���ڿ� ù���ڰ� A �� �� acnt++
			aCnt++;
		}
		else if (text[0] == 'P') { // ù���ڰ� P �� �� bcnt++
			pCnt++;
		}
		printf("%s\n", text); // Ȯ�ο� ���ڿ� ���
	}

	printf("A�� �����ϴ� �ܾ��� ��: %d\n", aCnt);
	printf("P�� �����ϴ� �ܾ��� ��: %d\n", pCnt);

	fclose(fp);

	return 0;
}