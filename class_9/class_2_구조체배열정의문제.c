#include <stdio.h>
typedef struct book {
	char name[20];
	char title[50];
	int page;
}Book;

int main(void) {
	Book books[3]; // 구조체 배열 선언

	printf("도서 정보 입력\n");
	for (int i = 0;i < 3;i++) {
		printf("저자: ");
		scanf_s("%s", books[i].name, 21); // . : 구조체 배열의 맴버 접근
		printf("제목: ");
		scanf_s("%s", books[i].title, 51); // . : 구조체 배열의 맴버 접근
		printf("페이지 수: ");
		scanf_s("%d", &books[i].page);
	}

	printf("\n도서 정보 출력\n");
	for (int j = 0;j < 3;j++) {
		printf("book %d\n", j + 1);
		printf("저자: %s\n", books[j].name);
		printf("제목: %s\n", books[j].title);
		printf("페이지 수: %d\n", books[j].page);
	}

	return 0;
}