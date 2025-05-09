#include <iostream>
using namespace std;

int main() {
	int a = 1234, b = 0x12345678;

	cout << hex << "16진수 a =" << a; // 4d2
	cout << dec << "\t10진수 a = " << a << endl; // 1234
	cout << hex << "16진수 b = " << b; // 12345678
	cout << dec << "\t10진수 b = " << b << endl; // 305419896

	return 0;
}