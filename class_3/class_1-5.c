// class_1-5.c : if 조건문 2
#include <stdio.h>
int main() {
	int opt;
	double num1, num2;
	double result;

	printf("1.덧셈 2.뺄셈 3.곱셈 4.나눗셈 \n");
	printf("선택? ");
	scanf_s("%d", &opt);
	printf("두 개의 실수 입력: ");
	scanf_s("%lf %lf", &num1, &num2); // 실수를 입력 받을 때의 서식문자는 %lf 사용 (double)

	// 반복적인 if 문과 if문들에 동일한 조건 변수가 있을 경우 switch ~ case 문을 활용하는 것이 더 가독성 있음
	if (opt == 1) {
		result = num1 + num2;
	}
	if (opt == 2) {
		result = num1 - num2;
	}
	if (opt == 3) {
		result = num1 * num2;
	}
	if (opt == 4) {
		result = num1 / num2;
	}
	printf("결과: %f \n", result);
	return 0;
	
	/* 위 if 문을 if ~ else if ~ else 문으로 변경
		if(opt==1){
			result = num1 + num2;}
		else if(opt==2){
			result = num1 - num2;}
		else if(opt==3){
			result = num1 * num2;}
		else {
			result = num1 / num2;}
	*/
}