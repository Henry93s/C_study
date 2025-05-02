// 매크로 함수의 단점
#include <stdio.h>
// 매크로로 구현했을 때
#define DIFF_ABS(X,Y) ((x)>(y)?(x)-(y):(y)-(x))

// 함수로 구현했을 때
double diff_abs(int x, int y) {
	double result = x > y ? (x - y) : (y - x);
	return result;
}

int main() {
	printf("두 값의 차: %g \n", diff_abs(5, 7));
	// printf("두 값의 차: %g \n", DIFF_ABS(1.8, -1.4)); // error
	// => 매크로 함수 매개변수 X 가 아니라 x 로 치환됨
	return 0;
}