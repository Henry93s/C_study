// ����ü�� ����ü ������ ������ Ȱ���� single linkedlist(���Ḯ��Ʈ)
#include <stdio.h>
struct point {
	int xpos;
	int ypos;
	struct point* ptr; // ����ü ���ο� ���� ����ü�� ������ ���� ����
};

int main() {
	struct point pos1 = { 1,1 }; // pos3 ���� ������ ����ü ���� ����
	struct point pos2 = { 2,2 };
	struct point pos3 = { 3,3 };

	pos1.ptr = &pos2;
	pos2.ptr = &pos3;
	pos3.ptr = &pos1;
	// pos 1 -> pos 2 -> pos 3 -> pos 1 ������ single ���Ḯ��Ʈ 
	// ==> ����ü ������ ������ �ٸ� ����ü �ɹ��� ���� !

	printf("���� �������... \n");
	printf("[%d, %d]��(��) [%d, %d] ���� \n"
		, pos1.xpos, pos1.ypos, pos1.ptr->xpos, pos1.ptr->ypos); // 1 1 2 2
	printf("[%d, %d]��(��) [%d, %d] ���� \n"
		, pos2.xpos, pos2.ypos, pos2.ptr->xpos, pos2.ptr->ypos); // 2 2 3 3
	printf("[%d, %d]��(��) [%d, %d] ���� \n"
		, pos3.xpos, pos3.ypos, pos3.ptr->xpos, pos3.ptr->ypos); // 3 3 1 1

	return 0;
}