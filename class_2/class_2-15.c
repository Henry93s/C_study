// class_2-15.c : 서식문자 %o : 8 진수, %x : 16 진수
#include <stdio.h>
int main() {
	int num1 = 7, num2 = 13;
	printf("%o %#o \n", num1, num1); // %o : 8진수, %#o : 8진수 표현 서식기호까지
	// -> 7 07
	printf("%x %#x \n", num2, num2); // %x : 16진수, %#x : 16진수 표현 서식기호까지
	// -> d oxd

	return 0;
}
