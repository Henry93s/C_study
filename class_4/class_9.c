// class_9.c : ���ڿ��� �����ϴ� ������ �迭
// ���ڿ��� char arr[] ������, ���ڿ� ������ �迭�� ��� char* arr[] �� �ּҸ� �����ϸ� �ȴ�.
#include <stdio.h>
int main() {
	char* strArr[3] = { "Simple", "String", "Array" };
	// ���ڿ� ������ �迭�� �� �ᱹ �ּҸ� �����ϸ� �ǹǷ� char* arr[] �÷� ���� �� �ʱ�ȭ�ϸ� ��!
	// -> char arr[] ���ڿ� ���� ������ char* arr[][] �� ȥ������ �� ��!
	printf("%s \n", strArr[0]); // Simple
	printf("%s \n", strArr[1]); // String
	printf("%s \n", strArr[2]); // Array

	return 0;
}
