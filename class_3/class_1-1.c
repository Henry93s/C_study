// class_1-1.c : do while -> ó�� while ���� ������ �����ϰ� �ݺ��� ���� Ȯ��
#include <stdio.h>
int main() {
	int total = 0, num = 0;

	do { // 1. ���ǰ� ������� �ϴ� �� ���� �ݺ����� �����Ѵ�.
		printf("���� �Է�(0 to quit): "); // 2. �ݺ���
		scanf_s("%d", &num);
		total += num;
	} while (num != 0); // 3. do~while ���� Ȯ��
	printf("�հ�: %d \n", total);

	return 0;
}