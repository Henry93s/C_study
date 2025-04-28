/*
	도전 3. 두 개의 정수를 입력 받아서 최대 공약수를 구하는 프로그램 작성.
	사전 확인 : 두 개의 정수 중 음수가 포함된 경우에도 최대공약수를 구할 수 있으며, 음수를 양수로 바꾼 후 계산한다.
*/
#include <stdio.h>
int FindMin(int num1, int num2) { // 두 수 중 작은 값을 반환하는 함수
	if (num1 < num2) {
		return num1;
	}
	else {
		return num2;
	}
}
int FindGcd(int min, int num1, int num2) { // 최대공약수 계산 함수
	int gcd;

	num1 == 0 && num2 == 0 ? (gcd = 0) : (num1 == 0 ? (gcd = num2) : (num2 == 0 ? (gcd = num1) : (gcd = 1)));
	// num1 == 0 && num2 == 0 ? (gcd = 0) -> num1 과 num2 모두 0 일 경우 gcd 는 0 으로 정의하는 것이 일반적.
	// 그 외 둘 중 하나가 0 일 경우 다른 하나의 정수가 최대 공약수.

	int i; // i 는 1 부터 min 값 까지 num1 과 num2 모두 i 로 나눠질 경우 계속해서 큰 값으로 최대공약수 변수 값이 저장 혹은 변경됨
	for (i = 1;i <= min; i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			gcd = i;
		}
	}

	return gcd;
}
int main(void) {
	int num1, num2; // 두 개의 정수를 입력 받는다.
	printf("최대공약수를 구할 두 개의 정수를 입력하세요 : "); // 정수를 입력받는 가이드 출력문
	scanf_s("%d %d", &num1, &num2); // 두 개의 정수를 입력 받음

	num1 < 0 ? (num1 = num1 * (-1)) : (num1 = num1); // 두 개의 정수 중 음수가 있을 때 양수로 변경
	num2 < 0 ? (num2 = num2 * (-1)) : (num2 = num2);

	int min = FindMin(num1, num2); // num1 과 num2 수 중 최솟값 저장을 위한 변수 선언 및 최소값 찾는 함수를 통한 초기화
	int gcd = FindGcd(min, num1, num2); // 최대공약수 변수 선언 및 함수 호출로 gcd 변수에 gcd 값 저장

	printf("두 수의 최대공약수: %d\n", gcd);
	return 0;
}