// class_1-10.c : continue �� break �� ����� Ư�� ������ ���
#include <stdio.h>
int main() {
	int i, j;
	for (i = 2;i < 10;i++) {
		if (i % 2 != 0) {
			continue; // 2�� ��� �ܸ� ����ϱ� ���Ͽ� i �� 2�� ����� �ƴ� ���� continue ó��
		}
		for (j = 1;j < 10;j++) {
			if (j > i) {
				break; // ��� �� ����� j �� i �� ������ ���� ��� ���� ����ϱ� ���ؼ� �� �̻��� j ���� ��� break �� �ݺ��� Ż��
			}
			printf("%d x %d = %d ", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}