// ����ü�� ���� ���
// �ϳ��� �޸� ������ �� �̻��� ������� ������ �� ���
#include <stdio.h>
typedef struct dbshort {
	unsigned short upper; // 2 byte
	unsigned short lower; // 2 byte
} DBShort;

typedef union rdbuf {
	int iBuf; // 4 byte
	char bBuf[4]; // 4
	DBShort sBuf; // 4
} RDBuf;

int main() {
	RDBuf buf; // 4 byte �Ҵ�
	printf("���� �Է�: ");
	scanf_s("%d", &(buf.iBuf)); // input : 1145258561

	printf("���� 2����Ʈ: %u\n", buf.sBuf.upper); // 16961
	printf("���� 2����Ʈ: %u\n", buf.sBuf.lower); // 17475
	printf("���� 1����Ʈ �ƽ�Ű �ڵ�: %c \n", buf.bBuf[0]); // A
	printf("���� 1����Ʈ �ƽ�Ű �ڵ�: %c \n", buf.bBuf[3]); // D

	return 0;
}