#include "class_18_매개변수의타입이다른_함수오버로딩.h"

int main() {
	int a = 34, b = 4;
	float c = 1.234f, d = 98.34f;
	char e = 'H', f = 'K';
	char str1[] = "computer", str2[] = "computers";

	// (a 가 클 경우 1, 아니면 - 1, 같으면 0)
	cout << Compare(a, b) << endl; // 1 
	cout << Compare(c, d) << endl; // -1
	cout << Compare(e, f) << endl; // -1
	cout << Compare(str1, str2) << endl; // -1

	return 0;
}