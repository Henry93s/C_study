// class_1-12.c : ÇÔ¼ö ±¸ÇöÇÏ±â(µ¡¼À func)
#include <stdio.h>
static int Add(int num1, int num2) { // Add ÇÔ¼ö »ý¼º
	return num1 + num2;
}
int main() {
	int result;
	result = Add(3, 4); // 3+ 4
	printf("µ¡¼À°á°ú1: %d\n", result);

	result = Add(5, 8); // 5 + 8
	printf("µ¡¼À°á°ú2: %d\n", result);

	return 0;
}