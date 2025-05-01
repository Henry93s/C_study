// 구조체 내부 문자열 변수 입력 및 수정
#include <stdio.h>
typedef struct person {
	char name[20];
	char phoneNum[20];
	int age;
} Person;

void ShowPersonInfo(Person man) {
	printf("name: %s \n", man.name);
	printf("phone: %s \n", man.phoneNum);
	printf("age: %d \n", man.age);
}

Person ReadPersonInfo() {
	Person man;
	printf("name? ");
	scanf_s("%s", man.name, 20); 
	// 구조체로 call by value 이므로 문자열의 주소가 반영되지 않아
	// scanf 동작이 되지 않음 !
	printf("phone? ");
	scanf_s("%s", man.phoneNum, 20);
	// 구조체로 call by value 이므로 문자열의 주소가 반영되지 않아
	// scanf 동작이 되지 않음 !
	printf("age? ");
	scanf_s("%d", &man.age);

	return man;
}

int main() {
	Person man = ReadPersonInfo();
	ShowPersonInfo(man);
	return 0;
}