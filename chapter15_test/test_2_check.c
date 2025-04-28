// 문제 2. 10진수 형태로 정수를 받고 2진수로 변환해서 출력하는 프로그램
#include <stdio.h>
int main() {
	int n;
	printf("10진수 정수 입력: ");
	scanf_s("%d", &n);
	int temp;

	while (n / 2 > 1) {
		temp = n;
		while (temp / 2 > 1) {
			temp /= 2;
		}
		printf("%d", temp % 2);
		n /= 2;
	}
	printf("0\n");

	return 0;
}