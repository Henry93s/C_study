// 지역변수 또는 전역변수로 해결이 되지 않는 경우
#include <stdio.h>
#include <stdlib.h> // 동적할당 헤더파일 추가
char name3[30];
// case 1. 함수에서 지역변수를 입력받고 반환 (stack)
char* ReadUserName() {
	char name[30]; // 입력을 받는 문자열이 지역변수로 선언되었고
	printf("whats your name? ");
	gets(name); // 입력을 받은 후 이 지역변수가
	return name; // 메모리에서는 소멸되기 때문에 main 함수에서는 비정상 값을 출력한다.
}
// case 2. 함수에서 전역변수를 입력받고 반환 (data)
char* ReadUserName2() {
	printf("name : ");
	gets(name3);
	return name3;
}
// case 3. 함수에서 동적할당 변수를 입력받고 반환 ( heap ! )
// => 문자열을 반환하는 함수를 정의하는 문제 해결
char* MallocUserName() {
	char* name = (char*)malloc(sizeof(char) * 30);
	printf("malloc name : ");
	gets(name);
	return name;
}

int main() {
	char* name1;
	char* name2;
	// case 1. 함수 내 에서 입력받는 지역변수 문자열인 지역변수 출력 (stack)
	name1 = ReadUserName();
	printf("name1: %s\n", name1); // 비정상 값 출력
	name2 = ReadUserName();
	printf("name2: %s\n", name2); // 비정상 값 출력
	
	// case 2. 전역변수 출력 (일단 해결은 되나 main 함수내 다른 변수에도 (data)
	// 수행한다면 이전의 name3 도 name4 와 같은 값이 된다.
	char* name3; 
	char* name4; 
	name3 = ReadUserName2();
	printf("name3: %s\n", name3); // 정상 
	name4 = ReadUserName2();
	printf("name4: %s\n", name4); // 정상

	printf("name3: %s\n", name3); // name4 와 동일한 값으로 출력됨

	// case 3. 함수 내 입력받는 문자열을 malloc 동적할당으로 넘긴 지역변수 출력 (heap)
	// 동적할당 변수는 heap 영역에 저장된다.
	// heap 영역의 경우 free 로 해제하지 않으면 프로그램 종료 후에도 메모리에 남게 된다.
	// 윈도우나 os 의 메모리 자동 최적화 등이 있지만 가능한 종료 직전 해제하는 것이 좋다.
	char* name5;
	char* name6;
	name5 = MallocUserName();
	printf("name5: %s\n", name5); //  정상
	name6 = MallocUserName();
	printf("name6: %s\n", name6); // 정상

	printf("name5, name6: %s %s\n", name5, name6); // 정상

	return 0;
}
