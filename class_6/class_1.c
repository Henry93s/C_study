// class_1.c : ���ڿ� ���� ����� �Լ� (gets, puts)
#include <stdio.h>
int main(void) {
	char* str = "Simple String";

	printf("1. puts test ------ \n");
	puts(str); // ���ڿ��� ����� ��ġ�� ���ڿ� �ּҰ��� ��ȯ�ǹǷ� �Ķ���ͷ� ���ڿ� �ּҰ��� ���޵�
	puts("So Simple String"); // 

	printf("2. fputs test ------ \n");
	fputs(str, stdout); // stdout : 2��° ���ڷ� stdout �� ���޵Ǿ� ����ͷ� ����� ��.
	printf("\n");
	fputs("So Simple String", stdout);
	printf("\n");

	printf("3. end of main ----\n");
	return 0;
}
