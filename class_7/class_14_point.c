// ����ü �ɹ� ����
#include <stdio.h>
typedef union ubox {
	int mem1;
	int mem2;
	double mem3;
} UBox;

int main() {
	UBox ubx; // 8 ����Ʈ �޸� �Ҵ�
	ubx.mem1 = 20;
	printf("%d\n", ubx.mem2); // 20 (�� mem1 ���� ���� �޸� ������ 20�� ������)

	ubx.mem3 = 7.15;
	printf("%d\n", ubx.mem1); // -1717986918 (mem3 �� ����Ǹ鼭 �޸� ������ ��������� ������)
	printf("%d\n", ubx.mem2); // -1717986918 (mem3 �� ����Ǹ鼭 �޸� ������ ��������� ������)
	printf("%g\n", ubx.mem3); // 7.15

	ubx.mem1 = 20;
	printf("%d\n", ubx.mem1); // 20
	printf("%d\n", ubx.mem2); // 20
	printf("%g\n", ubx.mem3); // 7.15

	return 0;
}