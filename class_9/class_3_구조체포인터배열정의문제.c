#include <stdio.h>
#include <stdlib.h>
typedef struct book {
	char name[20];
	char title[50];
	int page;
}Book;

int main(void) {
	/*
	Book books[3]; 
	Book* ptr[3]; // ����ü ������ �迭 ���� �� books ����ü �迭�� �ּҷ� �ʱ�ȭ
	for (int k = 0;k < 3;k++) {
		*(ptr + k) = &books[k];
	} // ����ü ������ �迭 �ʱ�ȭ (!) : ��, �� ���� *ptr ���� �߰� �ʿ�
	// �Ǵ� Book* ptr = (Book*)malloc(sizeof(Book)*3); 
	*/
	Book* ptr = (Book*)malloc(sizeof(Book) * 3);


	printf("���� ���� �Է�\n");
	for (int i = 0;i < 3;i++) {
		printf("����: ");
		scanf_s("%s", (ptr + i)->name, 21); // -> : ����ü �������� �ɹ� ����
		printf("����: ");
		scanf_s("%s", (ptr + i)->title, 51); // -> : ����ü �������� �ɹ� ����
		printf("������ ��: ");
		scanf_s("%d", &((ptr + i)->page)); // page �� int �� �ɹ��̹Ƿ� & �� �޾Ƽ� scanf_s ����
	}

	printf("\n���� ���� ���\n");
	for (int j = 0;j < 3;j++) {
		printf("book %d\n", j + 1);
		printf("����: %s\n", (ptr + j)->name);
		printf("����: %s\n", (ptr + j)->title);
		printf("������ ��: %d\n", (ptr + j)->page);
	}

	return 0;
}