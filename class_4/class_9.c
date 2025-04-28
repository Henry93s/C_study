// class_9.c : 문자열을 저장하는 포인터 배열
// 문자열은 char arr[] 이지만, 문자열 포인터 배열의 경우 char* arr[] 로 주소만 저장하면 된다.
#include <stdio.h>
int main() {
	char* strArr[3] = { "Simple", "String", "Array" };
	// 문자열 포인터 배열일 때 결국 주소만 저장하면 되므로 char* arr[] 꼴로 선언 및 초기화하면 됨!
	// -> char arr[] 문자열 개념 때문에 char* arr[][] 로 혼돈하지 말 것!
	printf("%s \n", strArr[0]); // Simple
	printf("%s \n", strArr[1]); // String
	printf("%s \n", strArr[2]); // Array

	return 0;
}
