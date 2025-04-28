// class 1_2.c : for 반복문 -> 반복의 횟수가 정해져있을 때 사용하면 좋음
// while 문은 반복문 내부를 비우면 안되지만, for 문의 반복문 내부는 비워도 정상 동작한다.
#include <stdio.h>
int main() {
	int total = 0;
	int i, num;
	printf("0부터 num까지의 덧셈, num은? ");
	scanf_s("%d", &num);

	for (int i = 0;i < num + 1;i++) // for(초기식; 조건식; 증감식) 구조
		total += i; // loop 문에서 2줄 이상일 때 중괄호를 사용하지만 한 줄일 때는 중괄호 없이 사용도 가능은 하다.

	printf("0부터 %d까지 덧셈 결과: %d \n",num,total);

	return 0;
}