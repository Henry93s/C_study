// class_1-21.c : 문자열 배열: 배열의 길이 선언 시 항상 인덱스 끝에 \0 문자까지 계산하여 선언
// -> tip : 문자열 배열에서는 
// -- \0 문자가 항상 인덱스 끝에 있으므로 반복문 활용 시에도 \0 까지 등 의 조건 활용 가능 !
#include <stdio.h>
int main() {
	char str[] = "Good morning!";
	printf("배열 str의 크기: %d \n", sizeof(str)); // 1 * 14 = 14 (13 + \0 문자)
	printf("널 문자 문자형 출력: %c \n", str[13]); // "" 출력(빈 문자)
	printf("널 문자 정수형 출력: %d \n", str[13]); // \0 은 정수형 출력일 때 0 으로 출력됨

	str[12] = '?'; // 저장된 배열 데이터 변경
	printf("문자열 출력: %s\n", str); // Good morning?
	return 0;
}