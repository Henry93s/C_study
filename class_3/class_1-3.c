// class_1-3.c : for ��ø�� : ������
#include <stdio.h>
int main() {
	int cur, is;

	for (cur = 2;cur < 10;cur++) { // �ʱ���� cur = 2 �̹Ƿ� 2�� ���� ����
		// cur < 10 : 2�ܺ��� 9�ܱ��� �������� ������ �� �� ����
		for (is = 1;is < 10;is++) { // �� ���� 1~9���� ���� ���� ���ϱ� ���� for �� ��ø��
			printf("%d x %d=%d \n", cur, is, cur * is);
			printf("\n");
		}
	}
	return 0;
}