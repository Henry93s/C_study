// class_1-1.c : Hello World & comment

#include <stdio.h> // #include : 다른 헤더 및 file 을 포함해서 compile 할 때 사용

int main(void) { 
	/* main 함수의 반환형은 integer, void 는 parameter 없다는 의미
		parameter 가 void 일 때 넘어오는 인자가 있으면 넘어온 인자가 무시됨
		parameter 가 비어있을 때 넘어오는 인자가 있으면 무시되지 않아 에러가 발생함
	*/

	printf("Hello, world! \n"); 
	/* printf : 모니터로 출력을 하는 경우에 쓴다. 인자로 문자열을 전달하면 문자열을 출력한다.
		c 기본 라이브러리 중 하나로 stdio.h 헤더 파일에서 가져와서 사용함(scanf 도 동일)
	*/

	/* 주석 : 코드에 30% 정도 작성되어야 좋음 
			// 블록 단위 주석은 중첩 불가하나, 블록 단위 주석 내 단일 행 주석은 중첩 가능함
	*/

	/* Programing 에서의 문장 : 세미콜론으로 종료되어야 프로그래밍에서 문장으로 취급함. 
		따라서 주석은 문장 아니지만 조건문, 반복문 같은 컨트롤 문장에는 세미콜론이 붙지 않음
	*/

	return 0;
}