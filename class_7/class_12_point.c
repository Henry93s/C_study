// 23-2 문제, 488p
#include <stdio.h>
typedef struct point {
	int xpos;
	int ypos;
} Point;

typedef struct rectangle { 
	Point x; // 첫 번째 점 좌표 (중첩 구조체 정의)
	Point y; // 두 번째 점 좌표 (중첩 구조체 정의)
} Rectangle;

int width(Rectangle* rectangle) { 
	// 매개 변수가 구조체 주소기 때문에 함수 내부에서 사용 시 구조체 포인터 변수
	// 처럼 -> 를 사용한다 !
	int x, y; // x : 가로 길이, y : 세로 길이
	x = (rectangle->y).xpos - (rectangle->x).xpos; 
	// 중첩 구조체 접근 시 괄호 필수 !
	y = (rectangle->y).ypos - (rectangle->x).ypos;
	return x * y;
}

int main() {
	Rectangle rect;
	
	scanf_s("%d %d", &rect.x.xpos, &rect.x.ypos);
	scanf_s("%d %d", &rect.y.xpos, &rect.y.ypos);

	printf("%d\n", width(&rect)); // 구조체의 주소를 넘김

	return 0;
}
