// ����ü �迭 ���� �� �ʱ�ȭ
#include <stdio.h>
#include <string.h>
struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

int main(void) {
	// ����ü �迭 ���� �� �ʱ�ȭ
	struct person arr[3] = { {"�ȼ���", "010-1234-5678", 23},
	{"ȫ�浿", "010-2345-6789", 25},
	{"��ö��", "010-3456-7890", 30} };
	
	int i;
	for (i = 0; i < 3; i++) {
		printf("�̸� : %s\n", arr[i].name);
		printf("��ȭ��ȣ : %s\n", arr[i].phoneNum);
		printf("���� : %d\n", arr[i].age);
	}

	return 0;
}