// ���̳ʸ� ���� �а� ����(copy ���)
#include <stdio.h>
int main() {
	FILE* src = fopen("src.bin", "rb"); // b : ���̳ʸ� ���
	FILE* des = fopen("des.bin", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) { // src �� des �� ���� �� ����ó��
		puts("���Ͽ��� ����!");
		return -1;
	}
	while (1) {
		readCnt = fread((void*)buf, 1, sizeof(buf), src);
		// ����ũ��, ���ڵ�ũ��, �����Ͱ���, �ҽ� ���̳ʸ� ���� ������
		if (readCnt < sizeof(buf)) {
			if (feof(src) != 0) {
				fwrite((void*)buf, 1, readCnt, des);
				puts("���Ϻ��� �Ϸ�!");
				break;
			}
			else {
				puts("���Ϻ��� ����!");
				
			}
			break;
		}
		fwrite((void*)buf, 1, sizeof(buf), des);
	}

	fclose(src);
	fclose(des);

	return 0;
}