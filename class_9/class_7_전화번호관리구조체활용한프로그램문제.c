#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct phonebook {
	char name[50];
	char phone[100];
	int test;
}Phonebook;

// ��ȭ��ȣ�ο� ���� �߰� �Լ�
void Insert(Phonebook* book, int* i) {
	char name[50];
	char phone[100];
	printf("\n[ INSERT ]\n");
	printf("Input Name: ");
	scanf_s("%s", name, 50);
	printf("Input Tel Number: ");
	scanf_s("%s", phone, 100);

	// �Լ����� ����ü ���ڿ� �ɹ��� ���� �Ҵ��� �� strncpy �Լ� ��� !!! 
	// ���ڿ� ������ ���� �Ҵ��� �� �ּҰ� �ݿ��Ǿ�� �ϹǷ�, �Ϲ� = �������� �Ұ�
	// -> �ּҸ� ����ϴ� string.h �Լ��� ����Ѵ� !
	strncpy_s((book + *i)->name, 50, name, 50); 
	// (book + *i)->name == book[*i].name !!!
	strncpy_s(book[*i].phone, 100, phone, 100);
	// (book + *i)->phone == book[*i].phone !!!
	*i += 1;
	return;
}
void Print(Phonebook* book, int* i) {
	printf("\n[ Print All Data ]\n");
	for (int j = 0;j < *i;j++) {
		printf("Name: %s\tTel: %s\n", book[j].name, book[j].phone);
	}
	return;
}
void Search(Phonebook* book, int* i) {
	int k;
	char name[50];

	printf("\n[ SEARCH ]\n");
	printf("INPUT Name: ");
	scanf_s("%s", name, 50);

	int findCnt = 0;
	for (k = 0;k < *i;k++) {
		if (strncmp((book + k)->name, name, 50) == 0) { // 0 �� �� ������ !!!
			printf("Find phone : %s\n", (book + k)->phone);
			findCnt++;
		}
	}
	if (findCnt == 0) {
		printf("Not Found Name\n");
	}
	return;
}
void Delete(Phonebook* book, int* i) {
	int k;
	char name[50];

	printf("\n[ Delete ]\n");
	printf("INPUT Name: ");
	scanf_s("%s", name, 50);

	int findCnt = 0;
	int findIndex = 0;
	for (k = 0;k < *i;k++) {
		if (strncmp((book + k)->name, name, 50) == 0) { // 0 �� �� ������ !!!
			findIndex = k;
			findCnt++;

			for (k = findIndex;k < (*i - 1);k++) { // ���� ��� ����ü �迭 �ε������� ������ �ε������� ������ ���Ҹ� ��ܿ� !
				strncpy_s(book[k].name, 50, book[k + 1].name, 50);
				strncpy_s((book + k)->phone, 100, (book + (k + 1))->phone, 100);
			}

			*i -= 1; // ����ü �迭 �ε��� - �ݿ�
		}
	}

	if (findCnt == 0) {
		printf("Not Found Name\n");
	}
	return;
}

int main() {
	Phonebook* book = (Phonebook*)malloc(sizeof(Phonebook) * 100);
	int bookIndex = 0;
	int op;

	while (1) {
		printf("***** MENU *****\n");
		scanf_s("%d", &op); // �޴� ��� scanf �� �Է¹���
		switch (op)
		{
		case 1:
			Insert(book, &bookIndex);
			break;
		case 2:
			Delete(book, &bookIndex);
			break;
		case 3:
			Search(book, &bookIndex);
			break;
		case 4:
			Print(book, &bookIndex);
			break;
		case 5:
			return 0;
			break;
		default:
			break;
		}
	}
}