/*
typedef struct div { // 구조체 typedef 정의
	int quotient;
	int remainder;
}Div;
*/
#include "class_1_구조체정의헤더파일.h" // 구조체가 정의된 헤더파일을 include !
#ifndef __class_1_구조체함수정의헤더파일_h__ // 조건부 매크로를 이용해 헤더파일의 중복삽입을 방지
#define __class_1_구조체함수정의헤더파일_h__
#endif // !__"class_1_구조체함수정의헤더파일_h"__
Div IntDiv(int num1, int num2) { // 외부 파일로 구조체를 활용한 함수 정의
	Div dval;
	dval.quotient = num1 / num2;
	dval.remainder = num1 % num2;
	return dval;
}