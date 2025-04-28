// class_2-14.c : 
// 명시적 형 변환 : 강제 형 변환
#include <stdio.h>
int main(void) {
	int num1 = 3, num2 = 4;
	double divResult;
	divResult = num1 / num2;
	printf("나눗셈 결과: %f \n", divResult); // 0.000000 <- 정수형 나눗셈 결과 몫이므로 0 이고 이를 %f 로 출력 했으므로
	divResult = (double)num1 / num2;
	printf("나눗셈 결과: %f \n", divResult); // 0.750000 <- num1 은 명시적 형 변환하고, 뒤 num2 는 묵시적 형 변환 된다. (3.0 / 4.0)

	return 0;
}
