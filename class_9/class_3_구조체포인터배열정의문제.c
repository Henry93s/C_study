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
	Book* ptr[3]; // 구조체 포인터 배열 선언 및 books 구조체 배열의 주소로 초기화
	for (int k = 0;k < 3;k++) {
		*(ptr + k) = &books[k];
	} // 구조체 포인터 배열 초기화 (!) : 단, 이 때는 *ptr 연산 추가 필요
	// 또는 Book* ptr = (Book*)malloc(sizeof(Book)*3); 
	*/
	Book* ptr = (Book*)malloc(sizeof(Book) * 3);


	printf("도서 정보 입력\n");
	for (int i = 0;i < 3;i++) {
		printf("저자: ");
		scanf_s("%s", (ptr + i)->name, 21); // -> : 구조체 포인터의 맴버 접근
		printf("제목: ");
		scanf_s("%s", (ptr + i)->title, 51); // -> : 구조체 포인터의 맴버 접근
		printf("페이지 수: ");
		scanf_s("%d", &((ptr + i)->page)); // page 는 int 형 맴버이므로 & 로 받아서 scanf_s 진행
	}

	printf("\n도서 정보 출력\n");
	for (int j = 0;j < 3;j++) {
		printf("book %d\n", j + 1);
		printf("저자: %s\n", (ptr + j)->name);
		printf("제목: %s\n", (ptr + j)->title);
		printf("페이지 수: %d\n", (ptr + j)->page);
	}

	return 0;
}