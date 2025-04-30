// 구조체 배열 선언 및 초기화
#include <stdio.h>
#include <string.h>
struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

int main(void) {
	// 구조체 배열 선언 및 초기화
	struct person arr[3] = { {"안성준", "010-1234-5678", 23},
	{"홍길동", "010-2345-6789", 25},
	{"김철수", "010-3456-7890", 30} };
	
	int i;
	for (i = 0; i < 3; i++) {
		printf("이름 : %s\n", arr[i].name);
		printf("전화번호 : %s\n", arr[i].phoneNum);
		printf("나이 : %d\n", arr[i].age);
	}

	return 0;
}