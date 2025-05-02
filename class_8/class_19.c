// 26-1 문제 2 576p
#include <stdio.h>
#define PI 3.14
#define AREA(r) (r)*(r)*(PI)

int main() {
	int r;
	scanf_s("%d", &r);

	printf("원 넓이: %g\n", AREA(r)); // 출력은 3.14 를 곱했기 때문에 double 형 반환

	return 0;
}