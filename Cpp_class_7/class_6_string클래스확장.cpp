#include "stringHeader.h"

void StringCharArray::toCharArray(char* str) {
	int i, len = this->length();
	for (i = 0;i < len;i++) {
		*(str + i) = this->at(i);
	}
	*(str + i) = '\0';
}

int main() {
	StringCharArray custom = "test"; // StringCharArray 생성자 체크 !
	char* charArray = new char[custom.length() + 1];
	
	custom.toCharArray(charArray);
	
	cout << charArray << endl;

	delete[] charArray;
	charArray = nullptr;

	return 0;
}