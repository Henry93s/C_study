// ����ü�� ����ü
// ����ü �޸� �Ҵ��� ��� �� �ɹ� ũ���� �� -> ��, �е��� ũ�⵵ �����Ѵ�.
// ����ü �޸� �Ҵ��� ��� �ɹ� �� ���� ū �ɹ� ũ��� �Ҵ�
// => �ٸ� �ɹ��� ���� ���� �޸� ������ ����ϸ鼭 ���� �� �ִ� ���� ���� !
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
	// 4 : int ������ �е� ũ��
	// 7 : char ������ �е� ũ��

	return 0;
}