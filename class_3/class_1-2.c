// class 1_2.c : for �ݺ��� -> �ݺ��� Ƚ���� ���������� �� ����ϸ� ����
// while ���� �ݺ��� ���θ� ���� �ȵ�����, for ���� �ݺ��� ���δ� ����� ���� �����Ѵ�.
#include <stdio.h>
int main() {
	int total = 0;
	int i, num;
	printf("0���� num������ ����, num��? ");
	scanf_s("%d", &num);

	for (int i = 0;i < num + 1;i++) // for(�ʱ��; ���ǽ�; ������) ����
		total += i; // loop ������ 2�� �̻��� �� �߰�ȣ�� ��������� �� ���� ���� �߰�ȣ ���� ��뵵 ������ �ϴ�.

	printf("0���� %d���� ���� ���: %d \n",num,total);

	return 0;
}