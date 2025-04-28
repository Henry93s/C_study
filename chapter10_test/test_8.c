/*
	도전 8. 2의 n승을 구하는 함수를 재귀적으로 구현해보자. 그에 따른 적절한 main 함수도 구현해보자.
*/
#include <stdio.h>
int calcPow(int n, int powNum, int cnt) {
	if (cnt < n) { // 2를 총 n 번 곱해야하므로 조건문에 따라 n 번 미만 곱했을 경우 재귀함수로 다시 동작
		calcPow(n, powNum * 2, cnt + 1); // 다시 재귀함수로 호출될 때는 powNum 에 2를 곱하고, cnt 를 1 증가시켜 함수 탈출 경로를 만듦.
	}
	else {
		return powNum; // 2를 n 번 곱했을 때 더 이상 재귀하지 않고 powNum 답 을 반환
	}
}
int main(void) {
	int n; // 입력받을 변수 선언
	printf("정수 입력: ");
	scanf_s("%d", &n); // n 정수 입력 받음

	printf("2의 %d승은 %d", n, calcPow(n, 1, 0)); // pow 계산 재귀함수를 호출하여 값을 받아온다. 
	// 2번째 파라미터 1 은 재귀함수 내부에서 계속 곱해질 값을 미리 보내는 것.
	// 3번째 파라미터 0 은 총 8 번 곱해야는데 이를 재귀함수 내에서 count 하고 재귀처리 또는 반환 처리를 위한 파라미터를 보내는 것.
	return 0;
}