// 458p ���� 22-1 ����ü ����(���ڿ� �Լ�) �غ���
#include <stdio.h>
#include <string.h>
struct employee { // ����ü ����
	char name[20];
	char personNum[20];
	int selary;
};

int main() {
	// ����ü ���� ����
	struct employee man1;

	scanf_s("%s", man1.name, sizeof(man1));
	scanf_s("%s", man1.personNum, sizeof(man1.personNum));
	scanf_s("%d", &man1.selary);

	printf("%s\n%s\n%d\n\n", man1.name, man1.personNum, man1.selary);

	// ����ü ���� ���� �� �ʱ�ȭ �� �߰�ȣ�� �����
	struct employee man2 = { "�ȼ���", "123456-1234567", 1000000 };
	printf("%s\n%s\n%d\n", man2.name, man2.personNum, man2.selary);

	return 0;
}