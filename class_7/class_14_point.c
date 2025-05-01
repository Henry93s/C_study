// 공용체 맴버 접근
#include <stdio.h>
typedef union ubox {
	int mem1;
	int mem2;
	double mem3;
} UBox;

int main() {
	UBox ubx; // 8 바이트 메모리 할당
	ubx.mem1 = 20;
	printf("%d\n", ubx.mem2); // 20 (위 mem1 에서 같은 메모리 공간에 20을 저장함)

	ubx.mem3 = 7.15;
	printf("%d\n", ubx.mem1); // -1717986918 (mem3 이 저장되면서 메모리 공간에 덮어써졌기 때문에)
	printf("%d\n", ubx.mem2); // -1717986918 (mem3 이 저장되면서 메모리 공간에 덮어써졌기 때문에)
	printf("%g\n", ubx.mem3); // 7.15

	ubx.mem1 = 20;
	printf("%d\n", ubx.mem1); // 20
	printf("%d\n", ubx.mem2); // 20
	printf("%g\n", ubx.mem3); // 7.15

	return 0;
}