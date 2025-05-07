#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct phonebook {
	char name[50];
	char phone[100];
	int test;
}Phonebook;

// 전화번호부에 정보 추가 함수
void Insert(Phonebook* book, int* i) {
	char name[50];
	char phone[100];
	printf("\n[ INSERT ]\n");
	printf("Input Name: ");
	scanf_s("%s", name, 50);
	printf("Input Tel Number: ");
	scanf_s("%s", phone, 100);

	// 함수에서 구조체 문자열 맴버에 값을 할당할 때 strncpy 함수 사용 !!! 
	// 문자열 변수에 값을 할당할 때 주소가 반영되어야 하므로, 일반 = 연산으로 불가
	// -> 주소를 사용하는 string.h 함수를 사용한다 !
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
		if (strncmp((book + k)->name, name, 50) == 0) { // 0 일 때 동일함 !!!
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
		if (strncmp((book + k)->name, name, 50) == 0) { // 0 일 때 동일함 !!!
			findIndex = k;
			findCnt++;

			for (k = findIndex;k < (*i - 1);k++) { // 삭제 대상 구조체 배열 인덱스부터 마지막 인덱스까지 앞으로 원소를 당겨옴 !
				strncpy_s(book[k].name, 50, book[k + 1].name, 50);
				strncpy_s((book + k)->phone, 100, (book + (k + 1))->phone, 100);
			}

			*i -= 1; // 구조체 배열 인덱스 - 반영
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
		scanf_s("%d", &op); // 메뉴 명령 scanf 로 입력받음
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