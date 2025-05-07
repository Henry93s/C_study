#include <stdio.h>

/*
typedef struct div {
	int quotient;
	int remainder;
} Div; // Div 구조체 정의 : 컴파일러는 파일 단위로 컴파일을 진행하므로
//						    Div 에 대한 선언 및 정의는 Div 를 필요로 하는 모든 파일에 존재해야함
// => 이 경우 헤더 파일에서 구조체를 정의해 한 번만 선언하도록 개선할 수 있음 !
*/

#include "class_1_구조체정의헤더파일.h" // 구조체가 정의된 헤더파일을 include !
#ifndef __class_1_구조체함수정의헤더파일_h__ // 조건부 매크로를 이용해 헤더파일의 중복삽입을 방지
#define __class_1_구조체함수정의헤더파일_h__ // . 대신 _ 기호 및 양끝에 __ 사용 !
#endif // !__class_1_구조체함수정의헤더파일_h__

extern Div IntDiv(int num1, int num2); // 외부에서 정의된 구조체를 활용한 함수를 사용함

int main() {
	Div val = IntDiv(5, 2);
	printf("몫: %d \n", val.quotient);
	printf("나머지: %d \n", val.remainder);

	return 0;
}