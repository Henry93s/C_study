// 458p 문제 22-1 구조체 정의(문자열 함수) 해보기
#include <stdio.h>
#include <string.h>
struct employee { // 구조체 정의
	char name[20];
	char personNum[20];
	int selary;
};

int main() {
	// 구조체 변수 선언
	struct employee man1;

	scanf_s("%s", man1.name, sizeof(man1));
	scanf_s("%s", man1.personNum, sizeof(man1.personNum));
	scanf_s("%d", &man1.selary);

	printf("%s\n%s\n%d\n\n", man1.name, man1.personNum, man1.selary);

	// 구조체 변수 선언 및 초기화 시 중괄호를 사용함
	struct employee man2 = { "안성준", "123456-1234567", 1000000 };
	printf("%s\n%s\n%d\n", man2.name, man2.personNum, man2.selary);

	return 0;
}