// ���� 4. palindrome ȸ�� �Ǵ� ���α׷�(��ҹ��ڱ��� ��ġ�ؾ� ȸ������ ����)
#include <stdio.h>
#include <string.h> // strlen �Լ��� ����ϱ� ���ؼ� ��� ���� �߰�
int isPalindrome(char str[]) {
	int i;
	int s = 0, e = strlen(str); // strlen �Լ� : str ���ڿ��� ���̸� ��ȯ�Ѵ�.
	// �Ǵ� ���ڿ��� ���ڸ� ��ȸ�ؼ� '\0' �� ���� ã�´�.
	int isTrue = 1;
	for (i = s;i < e / 2;i++) {
		if (str[i] != str[e - i - 1]) {
			isTrue = 0;
			break;
		}
	}
	return isTrue;
}
int main() {
	char str[1000];

	printf("���ڿ� �Է�: ");
	scanf_s("%s", str, 1000);
	// scanf_s ���� ���ڿ� �Է� �� ������ �Ķ���Ϳ� ũ�⸦ �����ؾ� ��.
	
	int isTrue = 0;
	isTrue = isPalindrome(str);
	if (isTrue) {
		printf("ȸ���Դϴ�.\n");
	}
	else {
		printf("ȸ���� �ƴմϴ�.\n");
	}

	return 0;
}