// class_2-11.c : 아스키 코드 (A : 65)
#include <stdio.h>
int main(void) {
	char ch1 = 'A', ch2 = 65;
	int ch3 = 'Z', ch4 = 90;

	printf("%c %d \n", ch1, ch2); // 문자 'A' 와 숫자 65 출력
	printf("%c %d \n", ch2, ch2); // 숫자 65의 아스키 코드를 가리키는 'A' 와 숫자 65 출력
	printf("%c %d \n", ch3, ch3); // 문자 'Z' 와 아스키 코드 90 출력
	printf("%c %d \n", ch4, ch4); // 숫자 90의 아스키 코드를 가리키는 'Z' 와 숫자 90 출력
	return 0;
}