// ���� 2. 10���� ���·� ������ �ް� 2������ ��ȯ�ؼ� ����ϴ� ���α׷�
#include <stdio.h>
int main() {
	int n;
	printf("10���� ���� �Է�: ");
	scanf_s("%d", &n);
	int temp;

	while (n / 2 > 1) {
		temp = n;
		while (temp / 2 > 1) {
			temp /= 2;
		}
		printf("%d", temp % 2);
		n /= 2;
	}
	printf("0\n");

	return 0;
}