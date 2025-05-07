#include <stdio.h>
#include <string.h>
int main(void) {
	FILE* fp1 = fopen("d1.txt", "rt");
	FILE* fp2 = fopen("d2.txt", "rt");

	char text1, text2; // ������ �ӽ÷� ��� ���� ���� ���� ����
	int same = 1; // �� ���� ������ ������ �ٸ��� �����ϱ� ���� ���� �ʱ�ȭ

	while (1) {
		text1 = fgetc(fp1); // ���� ���ڸ� �����ؼ� �� ���ھ� ���ڸ� ����.
		text2 = fgetc(fp2);
		if (text1 == EOF && text2 != EOF) { // ���� �� �߿� �ϳ��� EOF �� ��� �̹� ���̿��� ���� ���̰� �����Ƿ�
			// same �� false �� �����ϰ� break;
			same = 0;
			break;
		}
		else if (text2 == EOF && text1 != EOF) {
			same = 0;
			break;
		}

		if (text1 != text2) {
			same = 0;
			break; // ���� �� ���� ���� �ϳ��� ���ڰ� �ٸ� ��� �̹� �ٸ� �����̹Ƿ� break ó�� �� Ż��
		}
		if (text1 == EOF && text2 == EOF) {
			break; // ���� �� ���� ���̴� ��ġ��.
		}
	}

	if (same == 1) {
		printf("�� ���� ������ ������ ��ġ�մϴ�.\n");
	}
	else {
		printf("�� ���� ������ ��ġ���� �ʽ��ϴ�.\n");
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}