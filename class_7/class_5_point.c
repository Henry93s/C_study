// ����ü�� ���ǿ� typedef ����
// typedef �� ����ü���� ���� ���̴µ�, �Ϲ����� �� ����ü ������ �ʹ� �� ���� ���� �� �ֱ� ����.
#include <stdio.h>
struct point {
	int xpos;
	int ypos;
}; // �Ϲ� ����ü ����
typedef struct point Point; 
// ��� 1. typedef �� �ռ� ���ǵ� ����ü�� Point ��� �̸� �ο�

typedef struct person {
	char name[20];
	char phoneNum[20];
	int age;
}Person; // ��� 2. typedef �� ����ü ���ǿ� ���ÿ� Person �̶�� �̸��� �ο�

int main() {
	Point pos = { 10,20 }; // typedef �� �̸��� �ο��� point ����ü ���� ���� �� �ʱ�ȭ
	// struct point pos �� ���� !
	Person man = { "�̽±�", "010-1212-0001", 21 }; // typedef �� �̸��� �ο��� person ����ü ���� ���� �� �ʱ�ȭ
	// struct person man �� ���� !
	printf("%d %d \n", pos.xpos, pos.ypos);
	printf("%s %s %d \n", man.name, man.phoneNum, man.age);

	return 0;
}