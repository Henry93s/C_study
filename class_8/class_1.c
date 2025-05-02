// ���Ŀ� ���� 
// ����� fprintf, fscanf
#include <stdio.h>
int main() {
	char name[10];
	char sex;
	int age;

	// write
	FILE* fp = fopen("friend.txt", "wt");
	int i;

	for (i = 0;i < 3;i++) {
		printf("�̸� ���� ���� �� �Է�: ");
		scanf_s("%s %c %d", name, 10, &sex, 1, &age);
		while (getchar() != '\n'); // ���ۿ� �ִ� ���๮�� ����
		fprintf(fp, "%s %c %d\n", name, sex, age);
	}
	fclose(fp);

	// read
	fopen_s(fp, "friend.txt", "rt");
	int ret;
	
	while (1) {
		ret = fscanf_s(fp, "%s %c %d", name, 10, &sex, 1, &age);
		if (ret == EOF) { // end of file 
			break;
		}
		printf("%s %c %d \n", name, sex, age);
	}
	fclose(fp);

	return 0;
}