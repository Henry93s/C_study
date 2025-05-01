// 구조체를 정의와 typedef 선언
// typedef 는 구조체에서 많이 쓰이는데, 일반적인 긴 구조체 선언은 너무 길 때가 있을 수 있기 때문.
#include <stdio.h>
struct point {
	int xpos;
	int ypos;
}; // 일반 구조체 정의
typedef struct point Point; 
// 방법 1. typedef 로 앞서 정의된 구조체에 Point 라는 이름 부여

typedef struct person {
	char name[20];
	char phoneNum[20];
	int age;
}Person; // 방법 2. typedef 로 구조체 정의와 동시에 Person 이라는 이름을 부여

int main() {
	Point pos = { 10,20 }; // typedef 로 이름을 부여한 point 구조체 변수 선언 및 초기화
	// struct point pos 와 같다 !
	Person man = { "이승기", "010-1212-0001", 21 }; // typedef 로 이름을 부여한 person 구조체 변수 선언 및 초기화
	// struct person man 과 같다 !
	printf("%d %d \n", pos.xpos, pos.ypos);
	printf("%s %s %d \n", man.name, man.phoneNum, man.age);

	return 0;
}