// class_4.c : 
#include <stdio.h>
int main(int argc, char* argv[]) {
	int i;
	float f;
	char c, str[32];

	scanf_s("%d", &i);
	printf("���� : %d\n", i);
	scanf_s("%f", &f);
	printf("�Ǽ�: %f\n", f);
	// - ������ ���ڸ� �Է� �ް��� ���� �Է� ���ۿ� ���๮�ڸ� ���� ���
	// 1. �Է� ���� ����� ��� (while getchar() != '\n'); 
	/*
		while (getchar() != '\n');
		scanf_s("%c", &c, 1);
	*/

	// 2. ������ ����Ͽ� ���� ���ڸ� �����ϴ� ���
	// scanf_s(" %c", &c, 1); 
	
	// 3. %*c�� ����Ͽ� ���� ���� ����
	scanf_s("%*c%c", &c, 1); 
	
	printf("����: %c\n", c);
	
	scanf_s("%s", str, 32); 
	printf("���ڿ�: %s\n", str);

	return 0;
}