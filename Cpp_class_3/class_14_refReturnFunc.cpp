#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref) {
	ref++;
	return ref;
}
int& RefRetFuncOne2(int& ref) {
	ref++;
	return ref;
}
int RefRetFuncTwo(int& ref) {
	ref++;
	return ref;
}

int main() {
	// 1. 반환형이 참조하고 반환도 참조로 받을 경우
	int num1 = 1;
	int& num2 = RefRetFuncOne(num1);
	num1++;
	num2 += 100;

	cout << num1 << endl; // 103
	cout << num2 << endl; // 103


	// 2. 반환형이 참조하되 반환은 변수로 받을 경우
	int num3 = 1;
	int num4 = RefRetFuncOne2(num3);
	num3++;
	num4 += 100;

	cout << num3 << endl; // 3
	cout << num4 << endl; // 102


	// 3. 참조를 대상으로 값을 반환하는 경우
	int num6 = 1;
	int num7 = RefRetFuncTwo(num6);
	num6++;
	num7 += 100;

	cout << num6 << endl; // 3
	cout << num7 << endl; // 102

	return 0;
}