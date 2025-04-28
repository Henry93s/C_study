// class_7.c : 문자열 배열에서의 포인터 활용
#include <stdio.h>
int main() {
	char str1[] = "My String"; // 변수 형태의 문자열
	char* str2 = "Your String"; // 상수 형태의 문자열

	printf("%s %s \n", str1, str2);

	str2 = "Our String";
	printf("%s %s \n", str1, str2); // Your -> Our

	str1[0] = 'X'; // 변수 형태 문자열이므로 변경 성공
	printf("%s %s \n", str1, str2);
	str2[0] = 'X'; // 상수 형태 문자열이므로 변경 불가
	printf("%s %s \n", str1, str2); // str2 가 변경되지 않으며, 바로 위에서 변경 시도 시 에러 발생으로 프로그램 종료
	// 즉, 에러로 인해 printf 동작 x

	str2 = str1; // str2 주소를 변수 형태의 문자열의 주소로 변경했으므로
	printf("%s %s \n", str1, str2); // 는 정상 출력된다.

	return 0;
}