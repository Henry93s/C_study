#include <iostream>
#include <string>
using namespace std;

/*
	템플릿 : 일종의 틀로, 처리할 내용인 알고리즘은 동일하나
	처리 대상의 Type 이 여러 타입일 때 사용하는 것(함수, 클래스)
	- 함수나 클래스 작성 전에 "template <typename "name">" 선언 필요
	- 컴파일러가 인자 자료형을 확인하여 함수의 유형을 자동으로 결정
		* 과정 : 함수 템플릿 -> 템플릿 함수가 적용됨
*/
template <typename T>
// const 위치 상관없음
// == T const add, == T const& a
const T add(const T& a, const T& b) {
	return a + b;
}

// 둘 이상의 형(type) 에 대해서도 템플릿을 선언할 수 있음( , 구분 )
// 템플릿에서 키워드 typename 과 키워드 class 는 같은 의미로 사용
template <class T1, class T2>
void ShowData(double num) {
	cout << (T1)num << ", " << (T2)num << endl;
}

// 둘 이상의 인자에 대해서도 템플릿을 선언할 수 있음
template <typename T, typename R>
R MaxValue(const T num1, const R num2) {
	if (num1 > num2) {
		return num1;
	}
	else {
		return num2;
	}
}

// 인자가 템플릿 typename 3 개 중 어떤 type 인지 찾지 못해서 에러 발생 case
template <typename R, typename T, typename U>
const R add2(const T& a, const U& b) {
	return a + b;
}

// 특수화(specialization) 템플릿 : 기존 템플릿의 예외나 다른 case 를 정의한 템플릿
// 위 Maxvalue 의 특수화 템플릿 정의
template <>
char* MaxValue(char* a, char* b) {
	cout << "char* max<char*>(char* a, char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}
template <>
const char* MaxValue(const char* a, const char* b) {
	cout << "const char* max<const char*>(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

// 함수 템플릿 오버로딩 시 "template <typename>" 선언은 제외한다.
const char* MaxValue (char* a, const char* b) {
	cout << "const char* max<const char*>(char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main() {
	double i = 5.1;
	double j = 10.2;

	int a = 5;
	int b = 10;

	cout << i << " + " << j << " = " << add(i,j) << endl;
	cout << a << " + " << b << " = " << add(a,b) << endl;

	cout << endl;
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<char, double>(69.2);
	ShowData<char, double>(70.4);

	cout << endl;
	cout << MaxValue(3, 5) << endl;
	cout << MaxValue(9.1, 3.5) << endl; // 9.1
	cout << MaxValue(9.1, 3) << endl; // 9 
	// <- 3이 인자로 R 타입이고 반환도 R 타입이므로
	cout << MaxValue(3, 9.1) << endl; // 9.1 
	// <- 9.1이 인자로 R 타입이고 반환도 R 타입이므로

	cout << endl;
	double i2 = 5.1;
	int a2 = 5;
	// 인자가 템플릿 typename 3 개 중 어떤 type 인지 찾지 못해서 에러
	// cout << i2 << "+" << a2 << " = " << add2(i2, a2) << endl;

	cout << endl;
	// 특수화 템플릿 확인
	cout << MaxValue(3, 4) << endl;
	cout << MaxValue("simple", "best") << endl; // const char*
	char str1[] = "simple";
	char str2[] = "best";
	cout << MaxValue(str1, str2) << endl; // char*

	cout << endl;
	// 함수 템플릿 오버로딩 시 "template <typename>" 선언은 제외
	cout << MaxValue(str1, "best"); // const char*

	return 0;
}