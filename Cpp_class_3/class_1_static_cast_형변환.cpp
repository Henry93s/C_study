#include <iostream>
using namespace std;
int main() {
	float i = 100.12345; // '초기화 중': 'double'에서 'float'(으)로 잘립니다.
	double j = 200.12345;
	float count = static_cast<float>(j / i);

	double d = 1212;
	void* p = &d;
	double* dp = static_cast<double*>(p);

	d = 4.24;
	int* i1 = (int*)&d; // 컴파일은 성공
	int* i2 = static_cast<int*>(&d); // 컴파일 실패
	// 'static_cast': 'double *'에서 'int *'(으)로 변환할 수 없습니다.

	int i3 = dynamic_cast<int>(d); // 컴파일 에러(기본 자료형 불가)
	// 'int': dynamic_cast의 대상 형식이 잘못되었습니다.
	
	return 0;
}