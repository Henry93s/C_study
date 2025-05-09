#include <iostream>

using namespace std;

void plus1(int n) { n++; }
void plus2(int& n) { n += 2; } // int& n : 레퍼런스 변수 -> 메모리 복사 X
//void plus3(const int n) { n+=3; } // error : const
//void plus4(const int &n) { n+=4; } // error : const
int main(void)
{
	int num1 = 1;
	plus1(num1); cout << "1 : " << num1 << endl; // 1
	plus2(num1); cout << "2 : " << num1 << endl; // 3
	//plus3(num1); cout << "3 : " << num1 << endl;
	//plus4(num1); cout << "4 : " << num1 << endl;
	return 0;
}