// class_2-7.c : sizeof ������ : �Ҹ��ϴ� �޸� ũ�⸦ "����Ʈ" ������ ����ؼ� ��ȯ
#include <stdio.h>
int main(void) {
	char ch = 9;
	int inum = 1052;
	double dnum = 3.1415;
	printf("���� ch�� ũ��: %d \n", sizeof(ch)); // 1
	printf("���� inum�� ũ��: %d \n", sizeof(inum)); // 4
	printf("���� dnum�� ũ��: %d \n", sizeof(dnum)); // 8

	printf("char�� ũ��: %d \n", sizeof(char)); // 1
	printf("int�� ũ�� : % d \n", sizeof(int)); // 4
	printf("long�� ũ��: %d \n", sizeof(long)); // 4 -> gcc �� vscode ������ 8 ����Ʈ�� ��µ� 
	printf("long long�� ũ��: %d \n", sizeof(long long)); // 8
	printf("float�� ũ��: %d \n", sizeof(float)); // 4
	printf("double�� ũ��: %d \n", sizeof(double)); // 8
	/*  �Ʒ��� �ڵ�� 32bit, 64bit pc ��� �ڷ����� ũ�⸦ �����Ͽ� �����ϰ� ��µ�
		printf("char : %lu\n", sizeof(int8_t)); // 1
		printf("short : %lu\n", sizeof(int16_t)); // 2
		printf("int : %lu\n", sizeof(int32_t)); // 4
		printf("long : %lu\n", sizeof(int64_t)); // 8
		printf("float : %lu\n", sizeof(float)); // 4
		printf("double : %lu\n", sizeof(double)); // 8

	*/

	return 0;
}
