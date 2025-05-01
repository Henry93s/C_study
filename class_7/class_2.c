// 포인터 변수를 구조체의 멤버로 선언하기
// linkedlist, tree 등등 중요하게 활용됨 !
#include <stdio.h>
struct point {
	int xpos;
	int ypos;
};
struct circle {
	double radius;
	struct point* center; // 구조체 내부에 다른 구조체 포인터 변수 생성
	// 같은 구조체 포인터 변수도 생성 가능
};
int main() {
	struct point cen = { 2, 7 };
	double rad = 5.5;

	struct circle ring = { rad, &cen };
	printf("원의 반지름; %g\n", ring.radius);
	// 구조체 내부의 구조체 포인터 변수에 접근하기
	printf("원의 중심: [%d, %d]\n", (ring.center)->xpos, ring.center->ypos);

	return 0;
}