// class_1-2.c : 서식문자(conversion specifier)

#include <stdio.h>

int main(void) {
	printf("Hello Everybody\n");

	printf("%d\n", 1234);
	printf("%d %d\n", 10, 20);
	/*
		%d : 서식문자라고 불리며, 출력 대상의 출력 형태를 지정하는 용도로 사용된다.
			두 번째 전달인자부터 출력의 대상이 된다.
			%d 로 변수 뿐만 아니라 실제 숫자도 출력의 대상으로 지정할 수 있다. 
	*/

	return 0;
}