// ���ڿ� ������ �а� ����
#include <stdio.h>
int main() {
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("des.txt", "wt");
	char str[20];

	if (src == NULL || des == NULL) {
		puts("���Ͽ��� ����!");
		return -1;
	}

	while (fgets(str, sizeof(str), src) != NULL) { // fget's' �̹Ƿ� ���ڿ� ����
		// �� ������ �а� NULL ������ ������ des ���Ͽ� puts ���ڿ��� ����Ѵ�.
		fputs(str, des);
	}

	if (feof(src) != 0) { // feof �� 0 �� �ƴ� �� ��ȯ : ������ �Ϸ�
		puts("���Ϻ��� �Ϸ�!");
	}
	else {
		puts("���Ϻ��� ����!");
	}

	fclose(src);
	fclose(des);

	return 0;
}