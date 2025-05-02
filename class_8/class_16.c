// 문자열 내에서 매크로 매개변수 치환되도록 만들기 : # 연산자
#include <stdio.h>
#define STRING_JOB(A,B) #A "의 직업은 " #B "입니다."
// => 문자열에서도 "ABC " " DEF 는 "ABC  DEF" 와 같다. 

int main() {
	printf("%s \n", STRING_JOB(이동춘, 나무꾼));
	printf("%s \n", STRING_JOB(한상순, 사냥꾼));
	
	return 0;
}