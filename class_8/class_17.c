// ��ũ�� �����ڷ� �����ϱ�
#include <stdio.h>
#define STNUM(Y, S, P) ((Y)*100000+(S)*1000+(P))
// STNUM(Y, S, P) YSP �� ���� YSP �� �ϳ��� �ٸ� ������ �ν��Ϸ��� ��


#define STNUM2(Y, S, P) Y ## S ## P
// �ι�° print ���� ���� ���� ���� �ܼ� ���ڿ� ������ ���� ������� ## �� ����Ѵ�.

int main() {
	printf("�й�: %d\n", STNUM(10, 65, 175));
	printf("�й�: %d\n", STNUM(10, 65, 075)); // 075 �� ��� �տ� 0 ������
	// 8������ �νĵȴ�.
	printf("�й�: %d\n", STNUM2(10, 65, 075));

	return 0;
}