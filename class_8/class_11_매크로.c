// 매크로 함수 선행처리 동작
#include <stdio.h>
#define SQUARE(X) X*X

int main() {
	int num = 2;
	printf("square of num: %d\n", SQUARE(num));
	printf("square of -5: %d\n", SQUARE(-5));
	printf("square of 2.5: %g \n", SQUARE(2.5));

	// 비정상 결과 출력
	printf("square of 3+2: %d\n", SQUARE(3 + 2)); // 3+2*3+2 로 그대로 치환되기만 하기 때문에
	// 25 로 예상했던 결과가 아닌 3+(2*3)+2 인 11이 출력
	// 매크로 전처리기는 단순히 "치환" 한다는 개념

	// 비정상 결과 -> 정상 결과로 수정
	printf("square of (3+2): %d\n", SQUARE((3 + 2))); // (3+2)*(3+2)
	// 25 출력됨

	return 0;
}