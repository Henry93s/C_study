// ���� 22-2. 463p ����ü �迭�� ����
#include <stdio.h>
#include <string.h>
struct employee { // ����ü ����
	char name[20];
	char personNum[20];
	int selary;
};

int main() {
	// ����ü �迭 ����
	struct employee man[3];

	// ����ü �迭 ���� �Է�
	for (int i=0;i < 3;i++) {
		scanf_s("%s", man[i].name, sizeof(man[i].name));
		scanf_s("%s", man[i].personNum, sizeof(man[i].personNum));
		scanf_s("%d", &man[i].selary);
		while (getchar() != '\n'); // ���๮�� ����
	}

	// ����ü �迭 ���� ���
	for (int j=0;j < 3;j++) {
		printf("%s\n%s\n%d\n\n", man[j].name, man[j].personNum, man[j].selary);
	}

	return 0;
}