// class_2-3.c : 
// class_2-3.c : 콤마 연산자 -> 동일한 성격 또는 동일한 자격의 문장을 나열하는데 사용
#include <stdio.h>
int main(void) {
	int num1 = 1, num2 = 2;
	printf("Hello, "), printf("world! \n"); // Hello, world! 출력
	num1++, num2++; // 후위 증가 (연산 전 증가) 
	printf("%d ", num1), printf("%d ", num2), printf("\n"); // 후위 증가로 값이 증가됐으므로 2 3 출력
	
	/*
		수식에서 쉼표 연산자를 사용하면 안된다. (MISRA-C)
			예시 :  x = (y=1, y++) -> x=1, y=2
					x = (y=1, z=2) -> y=1, z=2, x=2
	*/
	return 0;
}