#include <stdio.h>
#define MAX(a,b) a > b ? (a) : (b)

int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);

	printf("max : %d", MAX(a, b));
	return 0;
}