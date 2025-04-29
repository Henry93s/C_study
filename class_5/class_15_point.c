// class_15.c : 함수 포인터를 매개변수에 사용
#include <stdio.h>
int WhoIsFirst(int age1, int age2, int (*cmp)(int n1, int n2)) { 
	// int (*cmp)(int n1, int n2) 함수 포인터를 매개변수에 사용 -> 넘어올때 함수 주소가 넘어오게됨.
	// 배열 포인터와 유사함
	return cmp(age1, age2);
}
int OlderFirst(int age1, int age2) {
	if (age1 > age2) {
		return age1;
	}
	else if (age1 < age2) {
		return age2;
	}
	else {
		return 0;
	}
}
int YoungerFirst(int age1, int age2) {
	if (age1 < age2) {
		return age1;
	}
	else if (age1 > age2) {
		return age2; 
	}
	else {
		return 0;
	}
}
int main() {
	int age1 = 20;
	int age2 = 30;
	int first;

	printf("입장순서 1 \n");
	first = WhoIsFirst(age1, age2, OlderFirst); // OlderFirst 함수 이름(주소) 이 파라미터에 입력됨 
	printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);
	
	printf("입장순서 2 \n");
	first = WhoIsFirst(age1, age2, YoungerFirst);
	printf("%d세와 %d세 중 %d세가 먼저 입장! \n\n", age1, age2, first);

	return 0;
}