// 446p ���� 3.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n = 2;
	char name[20], name2[20]; int name_index = 0, name2_index = 0;
	char num[20], num2[20]; int num_index = 0, num2_index = 0;

	char input[100], input2[100];
	fgets(input, sizeof(input), stdin);
	input[strlen(input) - 1] = '\0'; // gets : input �� �ִ� ���๮�� ó��
	fgets(input2, sizeof(input2), stdin);
	input2[strlen(input2) - 1] = '\0'; // gets : input �� �ִ� ���๮�� ó��
	// cf. scanf �� ��� �׳� ���� �޾Ƽ� �� �ϸ� ��.


	// 1. ���� Ǯ��
	int i, chk;
	chk = 0;
	for (i = 0;input[i] != '\0';i++) {
		if (chk == 0 && input[i] != ' ') {
			name[name_index++] = input[i];
		}
		else if (chk == 0 && input[i] == ' ') {
			chk = 1;
		}
		else {
			num[num_index++] = input[i];
		}
	}

	chk = 0;
	for (i = 0;input2[i] != '\0';i++) {
		if (chk == 0 && input2[i] != ' ') {
			name2[name2_index++] = input2[i];
		}
		else if (chk == 0 && input2[i] == ' ') {
			chk = 1;
		}
		else {
			num2[num2_index++] = input2[i];
		}
	}

	if (strcmp(name, name2) == 1) { // ���ڿ� �� �� 1, -1, 0 ��� �ۼ� �ʿ�!
		printf("�̸� ����\n");
	}
	if (strcmp(num, num2) == 1) {
		printf("���� ����\n");
	}

	// 2. ���� ��Ȱ� �ٸ� �� : atoi(&arr[index1+1]) �� ����ϰ�, ���� ���ϴ� �κ��� �Լ��� ����

	return 0;
}