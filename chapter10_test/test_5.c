/*
	도전 5. 10개의 소수(prime number) 를 출력하는 프로그램.
	실행의 예 : 2 3 5 7 11 13 17 19 23 29
*/
#include <stdio.h>
int main(void) {
	int count = 0; // 10개 소수 갯수가 넘었을 때 while 문 탈출을 위한 count
	
	int i, j;
	int prime_cnt; // 2 부터 각 수마다 소수인지 판단하는 변수
	for (i = 2; count < 10;i++) {
		prime_cnt = 0; // 소수인지 판단하는 변수 초기화
		for (j = i;j >= 1;j--) {
			if (i % j == 0) {
				prime_cnt++;
			}
		}
		if (prime_cnt == 2) {
			printf("%d ", i);
			count++; // 특정 i 가 자기 자신과 1 로만 나누어 떨어질 때 최종 소수 카운트를 증가
		}
	}

	return 0;
}