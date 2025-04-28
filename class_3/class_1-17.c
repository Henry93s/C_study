// class_1-17.c : 전역변수의 이해
#include <stdio.h>
void Add(int val); // parameter val 을 전역변수 num 에 더하는 함수
int num; // 전역변수는 프로그램이 끝날 때까지 메모리에 존재하는 변수
// 기본적으로는 0 으로 초기화됨. (지역변수의 경우 기본적으로 쓰레기값 초기화)
int main() {
	printf("num: %d\n", num); // 0 출력 <- 기본적으로 0 으로 초기화되기 떄문에
	Add(3); // num => 3;
	printf("num: %d\n", num); // 3
	num++;	// num => 4
	printf("num: %d\n", num); // 4
	return 0;
}
void Add(int val) {
	num += val;
}