// class_10.c : 445 p ���ڿ��� �Է¹޾Ƽ� ���� �Ǵ� + ���� �� �� ���ϱ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // isdigit, 
int main() {
	char str[1000]; // buffer size ��ŭ ����.
	scanf_s("%s", str, 1000);

	int sum = 0;
	int i;
	
	// �� ���ڿ��� ���ڸ� ã�� ���ڵ��� �� ���ϱ�
	for (i = 0;i < strlen(str);i++) {
		if (isdigit(str[i])) {
			// sum += atoi(str[i]); 
			// �� sum Error : atoi �� ���ڿ��� ������ �ٲ��ִ� �Լ�
			sum += str[i] - '0'; // ���ڸ� ������ �ٲ�!
		}
	}

	// isdigit ���� �����ؼ� �ۼ��ϱ�(���ڳ��� ����)
	/*
	  char str[BUFSIZ], tmp[BUFSIZ];
	  long sum = 0, cnt = 0;

	  printf("Input some string : ");
	  scanf("%s", str);

	  for(int i = 0; i <= strlen(str); i++) {
		if(str[i] >= '0' && str[i] <= '9') {
		  tmp[cnt++] = str[i];
		} else if(cnt!=0) {
		  tmp[cnt] = '\0';
		  printf("%s+", tmp);
		  sum += atoi(tmp);
		  cnt = 0;
		}
	  }
	  printf("\b=%ld\n", sum);
	*/
	

	printf("%d\n", sum);

	return 0;
}