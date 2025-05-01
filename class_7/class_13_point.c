// 구조체와 공용체
// 구조체 메모리 할당의 경우 각 맴버 크기의 합 -> 단, 패딩의 크기도 포함한다.
// 공용체 메모리 할당의 경우 맴버 중 가장 큰 맴버 크기로 할당
// => 다른 맴버의 값이 같은 메모리 공간을 사용하면서 변할 수 있는 점을 유의 !
#include <stdio.h>
typedef struct s_data {
	int d1;
	double d2;
	char d3;
} S_data;
typedef union u_data {
	int d1;
	double d2;
	char d3;
} U_data;

int main() {
	S_data s;
	U_data u;

	printf("%d %d\n", sizeof(s), sizeof(u)); // 24(13 + 4 + 7) 8
	// 4 : int 에서의 패딩 크기
	// 7 : char 에서의 패딩 크기

	return 0;
}