/*
	도전 7. 숫자 n 을 입력받는다. 그리고 나서 '2의k승제곱 <= n' 을 성립하는 k 의 최댓값을 계산해서 출력하는 프로그램
*/
#include <stdio.h>
int main(void) {
	int n; // 상수 n 변수 선언
	printf("상수 n 입력: "); 
	scanf_s("%d", &n);

	int i; // 최종 결과값으로 2를 몇 번 곱했는지를 나타낸다.
	int mul = 2; // 초기값 2 부터 시작
	for (i = 1; mul * 2 <= n; i++) {
		mul *= 2; // 초기값은 계속 해서 2 가 곱해지면서 n 에 가장 가까워진다.
		printf("%d\n", mul);
	}
	printf("공식을 만족하는 k의 최댓값은 %d\n", i); // n 에 가까워질 동안 2를 몇 번 곱했는지 (i) 값 출력

	return 0;
}