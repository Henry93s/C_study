// ����ü �迭 ����
#include <stdio.h>
struct point { // ����ü ����
	int xpos;
	int ypos;
};

int main() {
	// ����ü ���� ����
	struct point arr[3];
	int i;

	for (i = 0; i < 3; i++) {
		printf("xpos, ypos �Է�: ");
		scanf_s("%d %d", &arr[i].xpos, &arr[i].ypos); // ����ü �迭 ����� �ּ� ����
	}

	for (i = 0; i < 3; i++) {
		printf("xpos: %d, ypos: %d\n", arr[i].xpos, arr[i].ypos); // ����ü �迭 ����
	}

	return 0;
}