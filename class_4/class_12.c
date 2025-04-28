// class_12.c : call by value 값 swap (안됨)
#include <stdio.h>
void swap(int n1, int n2) { // call by value 를 통해 swap 함수를 수행해도 실제 main 에서는 변경되지 않음.
	int temp = n1;
	n1 = n2;
	n2 = temp;
	printf("n1 n2 : %d %d \n", n1, n2); // 복사된 변수에서 변경된 데이터 출력
}
int main() {
	int num1 = 10;
	int num2 = 20;
	printf("num1 num2: %d %d \n", num1, num2);

	swap(num1, num2); // call by value 로 값이 파라미터로 복사되는 개념이기 때문에 
	// 아래의 결과에서 위 printf 와 동일한 결과를 출력한다.
	printf("num1 num2: %d %d \n", num1, num2);
	return 0;
}
