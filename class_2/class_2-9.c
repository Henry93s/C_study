// class_2-9.c : 실수 자료형 double 
/*
	소수점 이하 정밀도: float(4 byte) < double(8 byte) < long double(12 byte)
*/
#include <stdio.h>
int main() {
	double rad;
	double area;
	printf("원의 반지름 입력: ");
	scanf_s("%lf", &rad); // double 형 데이터를 입력 받을 때(scanf)는 서식문자 %lf 사용
	// float 형 데이터의 경우 모두 %f 서식문자 사용
	area = rad * rad * 3.1415;
	printf("원의 넓이: %f \n", area); // double 형 데이터를 출력할 때(printf) 서식문자 %f 나 %lf 사용

	return 0;
}