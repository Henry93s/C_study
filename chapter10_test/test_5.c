/*
	���� 5. 10���� �Ҽ�(prime number) �� ����ϴ� ���α׷�.
	������ �� : 2 3 5 7 11 13 17 19 23 29
*/
#include <stdio.h>
int main(void) {
	int count = 0; // 10�� �Ҽ� ������ �Ѿ��� �� while �� Ż���� ���� count
	
	int i, j;
	int prime_cnt; // 2 ���� �� ������ �Ҽ����� �Ǵ��ϴ� ����
	for (i = 2; count < 10;i++) {
		prime_cnt = 0; // �Ҽ����� �Ǵ��ϴ� ���� �ʱ�ȭ
		for (j = i;j >= 1;j--) {
			if (i % j == 0) {
				prime_cnt++;
			}
		}
		if (prime_cnt == 2) {
			printf("%d ", i);
			count++; // Ư�� i �� �ڱ� �ڽŰ� 1 �θ� ������ ������ �� ���� �Ҽ� ī��Ʈ�� ����
		}
	}

	return 0;
}