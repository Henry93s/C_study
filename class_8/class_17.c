// 매크로 연산자로 연결하기
#include <stdio.h>
#define STNUM(Y, S, P) ((Y)*100000+(S)*1000+(P))
// STNUM(Y, S, P) YSP 의 경우는 YSP 를 하나의 다른 값으로 인식하려고 함


#define STNUM2(Y, S, P) Y ## S ## P
// 두번째 print 문과 같은 경우로 인해 단순 문자열 연결을 위한 방법으로 ## 을 사용한다.

int main() {
	printf("학번: %d\n", STNUM(10, 65, 175));
	printf("학번: %d\n", STNUM(10, 65, 075)); // 075 의 경우 앞에 0 때문에
	// 8진수로 인식된다.
	printf("학번: %d\n", STNUM2(10, 65, 075));

	return 0;
}