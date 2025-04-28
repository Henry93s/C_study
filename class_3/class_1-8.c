// class_1-8.c : 189 p 문제 1, 7의 배수와 9의 배수, 7과 9의 배수 모두 만족하는 값을 중복되지 않게 출력하기
#include <stdio.h>
int main() {
	int i = 1;
	while (i < 100) {
		if (i % 7 == 0 && i % 9 == 0) { // if ~ else 문을 작성할 때 가장 범위가 좁은 조건을 우선 if 문으로 작성한다.
			printf("7의 배수와 9의 배수 모두 만족하는 값 : %d\n", i);
		}
		else if (i % 7 == 0) {
			printf("7의 배수 : %d\n", i);
		}
		else if (i % 9 == 0) {
			printf("9의 배수 : %d\n", i);
		} else {}
		i++;
	}
	return 0;
}