#include "basicArith.h" // PI 로 인한 헤더파일 추가
double TriangleArea(double base, double height) {
	return Div(Mul(base, height), 2);
}
double CircleArea(double rad) {
	return Mul(Mul(rad, rad), PI);
}