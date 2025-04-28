// class_1-3.c : for 중첩문 : 구구단
#include <stdio.h>
int main() {
	int cur, is;

	for (cur = 2;cur < 10;cur++) { // 초기식이 cur = 2 이므로 2단 부터 시작
		// cur < 10 : 2단부터 9단까지 구구단을 구함을 알 수 있음
		for (is = 1;is < 10;is++) { // 각 단의 1~9까지 곱한 값을 구하기 위한 for 문 중첩문
			printf("%d x %d=%d \n", cur, is, cur * is);
			printf("\n");
		}
	}
	return 0;
}