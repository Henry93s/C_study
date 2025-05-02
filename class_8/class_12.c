#include <stdio.h>
// 매크로 정의 시 기존에 정의된 매크로도 사용 가능함
// 원래는 순차적으로 동작해서 순서가 중요하나 컴파일러에 따라 동작할 수 있음
#define CIRCLE_AREA(R) (PRODUCT((R), (R))*PI)
#define PI 3.14
#define PRODUCT(X,Y) ((X)*(Y))



int main() {
	double rad = 2.1;
	printf("반지름 %g인 원의 넓이: %g \n", rad, CIRCLE_AREA(rad));

	return 0;
}