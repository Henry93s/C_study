// class_1-16.c : 세 수 중에서 가장 큰 수 또는 가장 작은 수 구하는 함수
#include <stdio.h>
int GetMax(int a, int b, int c) { // 세 수 중 가장 큰 수 반환 함수 생성 및 초기화
	int max;
	a > b ? (max = a) : (max = b); // 처음 비교 시 큰 수를 임시로 max 에 저장
	max > c ? (max = max) : (max = c); // 마지막 수와 비교하여 최종 max 값 결정
	return max;
}
int GetMin(int a, int b, int c) { // 세 수 중 가장 작은 수 반환 함수 생성 및 초기화
	int min;
	a < b ? (min = a) : (min = b); // 처음 비교 시 작은 수를 임시로 min 에 저장
	min < c ? (min = min) : (min = c); // 마지막 수와 비교하여 최종 min 값 결정
	return min;
}
int main() {
	int a, b, c;
	printf("세 수를 입력 : ");
	scanf_s("%d %d %d", &a, &b, &c);
	printf("세 수 중 가장 큰 수 : %d\n", GetMax(a, b, c));
	printf("세 수 중 가장 작은 수 : %d\n", GetMin(a, b, c));

	return 0;
}