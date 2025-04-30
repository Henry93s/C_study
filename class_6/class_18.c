// 문제 22-2. 463p 구조체 배열의 선언
#include <stdio.h>
#include <string.h>
struct employee { // 구조체 정의
	char name[20];
	char personNum[20];
	int selary;
};

int main() {
	// 구조체 배열 선언
	struct employee man[3];

	// 구조체 배열 정보 입력
	for (int i=0;i < 3;i++) {
		scanf_s("%s", man[i].name, sizeof(man[i].name));
		scanf_s("%s", man[i].personNum, sizeof(man[i].personNum));
		scanf_s("%d", &man[i].selary);
		while (getchar() != '\n'); // 개행문자 제거
	}

	// 구조체 배열 정보 출력
	for (int j=0;j < 3;j++) {
		printf("%s\n%s\n%d\n\n", man[j].name, man[j].personNum, man[j].selary);
	}

	return 0;
}