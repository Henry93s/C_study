// ���̳ʸ� ������ ����ü�� ����ü ������ �����
#include <stdio.h>
typedef struct fren {
	char name[10];
	char sex;
	int age;
} Friend;

int main() {
	Friend myfren1;
	Friend myfren2;

	// write
	FILE* fp = fopen("friend.bin", "wb"); // ����ü ������ �����ϱ� ���ؼ� ���̳ʸ� ���� ���� ����
	printf("�̸�, ����, ���� �� �Է�: ");
	scanf_s("%s %c %d", myfren1.name, 10, &(myfren1.sex), 1, &(myfren1.age));
	// fwrite �Լ��� �����͸� ����Ʈ ������ �����ϱ� ������
	// ����ü ������ �ѹ��� ������ �� ����.
	fwrite((void*)&myfren1, sizeof(myfren1), 1, fp);
	fclose(fp);

	// read
	fopen_s(fp, "friend.bin", "rb"); 
	// fread �� ����ü ������ �ѹ��� ���� �� ����.
	fread((void*)&myfren2, sizeof(myfren2), 1, fp);
	printf("%s %c %d\n", myfren2.name, myfren2.sex, myfren2.age);
	fclose(fp);

	return 0;
}