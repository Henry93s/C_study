// class_10.c : 445 p 문자열을 입력받아서 숫자 판단 + 숫자 총 합 구하기
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // isdigit, 
int main() {
	char str[1000]; // buffer size 만큼 받음.
	scanf_s("%s", str, 1000);

	int sum = 0;
	int i;
	
	// 각 문자에서 숫자를 찾고 숫자들의 합 구하기
	for (i = 0;i < strlen(str);i++) {
		if (isdigit(str[i])) {
			// sum += atoi(str[i]); 
			// 위 sum Error : atoi 는 문자열을 정수로 바꿔주는 함수
			sum += str[i] - '0'; // 문자를 정수로 바꿈!
		}
	}

	// isdigit 말고 분해해서 작성하기(숫자끼리 덧셈)
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