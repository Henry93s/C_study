// �����Ҵ� ����
#include <stdio.h>
#include <stdlib.h>
int main() {
	int* ptr1 = (int*)malloc(sizeof(int)); // �� �޸� ������ 4 ����Ʈ �Ҵ�
	int* ptr2 = (int*)malloc(sizeof(int) * 7); // 4 * 7 = 28 ����Ʈ �Ҵ�

	int i;
	*ptr1 = 20;
	for (i = 0;i < 7;i++) {
		ptr2[i] = i + 1;
	}

	printf("%d \n", *ptr1);
	for (i = 0;i < 7;i++) {
		printf("%d ", ptr2[i]);
	}

	free(ptr1); // ������ heap ������ �ִ� �޸𸮸� �����ϴ� ���� ����.
	free(ptr2);

	return 0;
}