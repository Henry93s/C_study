// 함수 포인터를 매개변수로 활용하여 계산기 만들기 실습 문제
#include <stdio.h>
float add(int n1, int n2) {
	return n1 + n2;
}
float minus(int n1, int n2) {
	return n1 - n2;
}
float mul(int n1, int n2) {
	return n1 * n2;
}
float div(int n1, int n2) {
	return n1 / n2;
}
// 매개변수에 함수 포인터 추가
float calculate(int n1, int n2, float (*func)(int n1, int n2)) {
	return func(n1, n2);
}
int main(void) {
	int n1, n2;
	char op; // 연산 기호
	float result = 0;

	printf("연산 기호 입력 : ");
	scanf_s("%c", &op, 1);
	printf("n1 n2 입력 : ");
	scanf_s("%d %d", &n1, &n2);

	if (op == '+') {
		result = calculate(n1, n2, add);
	}
	else if (op == '-') {
		result = calculate(n1, n2, minus);
	}
	else if (op == '*') {
		result = calculate(n1, n2, mul);
	}
	else if (op == '/') {
		result = calculate(n1, n2, div);
	}

	printf("계산 결과 : %.2f", result);
	
	return 0;
}