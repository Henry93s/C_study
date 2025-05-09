#ifndef _COMPARE_H_
#define _COMPARE_H_

#include <iostream>
using namespace std;

// 매개변수의 타입이 다른 함수 오버로딩 선언
int Compare(const int a, const int b);
int Compare(const float a, const float b);
int Compare(const char a, const char b);
int Compare(const char str1[], const char str2[]);

#endif // !_COMPARE_H_
