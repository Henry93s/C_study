#include <stdio.h>
typedef struct book {
	char name[20];
	char title[50];
	int page;
}Book;

int main(void) {
	Book books[3]; // ����ü �迭 ����

	printf("���� ���� �Է�\n");
	for (int i = 0;i < 3;i++) {
		printf("����: ");
		scanf_s("%s", books[i].name, 21); // . : ����ü �迭�� �ɹ� ����
		printf("����: ");
		scanf_s("%s", books[i].title, 51); // . : ����ü �迭�� �ɹ� ����
		printf("������ ��: ");
		scanf_s("%d", &books[i].page);
	}

	printf("\n���� ���� ���\n");
	for (int j = 0;j < 3;j++) {
		printf("book %d\n", j + 1);
		printf("����: %s\n", books[j].name);
		printf("����: %s\n", books[j].title);
		printf("������ ��: %d\n", books[j].page);
	}

	return 0;
}