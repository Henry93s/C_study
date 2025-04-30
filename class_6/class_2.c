// class_2.c : fgets 문자열 입 출력 함수
#include <stdio.h>
int main() {
	char str[7];
	int i;

	for (i = 0;i < 3;i++) {
		fgets(str, sizeof(str), stdin); 
		// gets 는 길이제한이 없어 버퍼가 깨지는 문제(버퍼 오버플로우)가 발생할 수 있어서 
		// scanf 와 같이 gets_s 로 사용(visual studio), linux 는 gets 가능
		printf("Read %d: %s\n", i + 1, str);
	}

	return 0;
}