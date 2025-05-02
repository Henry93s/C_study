// 조건부 컴파일을 위한 매크로 : #if ... #endif
#include <stdio.h>
#define ADD 1
#define MIN 0

int main() {
	int num1, num2;
	printf("두 개의 정수 입력; ");
	scanf_s("%d %d", &num1, &num2);

#if ADD // ADD 가 참일 때 (조건부 컴파일의 경우 조건에 따라 #if ~ #endif 내부 동작을 가능케한다.
	printf("%d + %d = %d\n", num1, num2, num1 + num2); // 동작
#endif

#if MIN // MIN 이 참일 때 -> 0
	printf("%d - %d = %d\n", num1, num2, num1 - num2); // 동작하지 않음!!!
#endif

	return 0;
}