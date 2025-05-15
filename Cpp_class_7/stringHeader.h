#ifndef _STR_H_
#define _STR_H_
#define MAX 50
#include <iostream>
#include <string>
using namespace std;

class StringCharArray : public string {
public:
	StringCharArray(const char* s) : string(s) {}
	void toCharArray(char* str);
};
#else
#endif // !_STR_H_
