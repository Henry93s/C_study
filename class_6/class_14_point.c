// ����ü�� ���ڿ� �Լ� ���
#include <stdio.h>
#include <string.h>
struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

int main(void) {
	struct person man1, man2;
	// ! ����ü ���� ���ڿ��� ���� �ִ� ���
	// (man1.name = "�ȼ���" �� �ּҰ� �Ѿ�� �ʾ����Ƿ� ���� �Ұ� �� ������ ����))
	// -> ���ڿ� ������ ���ؼ��� strcpy_s() �Ǵ� strncpy_s() ����Ѵ�.
	strncpy_s(man1.name, sizeof(man1.name), "�ȼ���", sizeof(man1.name));
	strncpy_s(man1.phoneNum, sizeof(man1.phoneNum), "010-1122-3344", sizeof(man1.phoneNum));
	man1.age = 23;
	/* strcpy �� strncpy ���� ! (�ٸ� strn~ �� ����)
		strcpy_s : (destination, destination size, source)
		strncpy_s : (destination, destination size, source, source size)
				source size: ������ ���ڿ��� ����
	*/

	printf("�̸� �Է�: ");
	scanf_s("%s", man2.name, sizeof(man2));
	printf("��ȭ��ȣ �Է�: ");
	scanf_s("%s", man2.phoneNum, sizeof(man2.phoneNum));
	printf("���� �Է�: ");
	scanf_s("%d", &man2.age);

	printf("�̸� : %s\n", man1.name);
	printf("��ȭ��ȣ : %s\n", man1.phoneNum);
	printf("���� : %d\n", man1.age);
	printf("\n");

	printf("�̸� : %s\n", man2.name);
	printf("��ȭ��ȣ : %s\n", man2.phoneNum);
	printf("���� : %d\n", man2.age);

	return 0;
}