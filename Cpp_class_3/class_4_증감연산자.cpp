#include <iostream>
using namespace std;
int main() {
	int a = 0, b = 0, sum1, sum2;
	sum1 = a++ + a++ + a++;
	sum2 = ++b + ++b + ++b;
	
	printf("%d %d %d %d\n", a, b, sum1, sum2);
	// 플랫폼마다 다르나, vs 의 경우 a : 3, b : 3, sum1 : 0, sum2 : 9 출력됨
	// gcc 컴파일러의 경우 : 3 3 3 7 출력됨.
	return 0;
}