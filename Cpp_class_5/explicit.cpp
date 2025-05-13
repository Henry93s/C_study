#include <iostream>
using namespace std;

class Widget {
public:
	// 1. 
	// Widget(int x) : a(x) {}

	// 2. Widget 사용자 정의 클래스(객체)가 생성될 때 "암묵적" 형변환을 허용하지 않는다.
	explicit Widget(int x) : a(x) {}
	int getvalue();
private:
	int a;
};
int Widget::getvalue() {
	return a;
}

void print(Widget&& rhs) {
	// 10 r-value 가 전달되었을 때, 
	// 클래스 내부 생성자 정의에 따라 "암묵적"인 형변환이 발생하고
	// print 함수 내부에서 Widget 임시 객체가 생성된다
	cout << rhs.getvalue() << endl;
}

int main() {
	// 1. 암묵적인 형 변환이 발생하는 케이스
	// print(10); // r-value 10 을 print 함수 매개변수로 전달

	// explicit
	// 2. 암묵적인 형 변환으로 인해 에러가 발생하는 케이스
	// r-value 10 으로 인해 Widget 임시 객체가 생성될 때 explicit 키워드로 인해 에러가 발생하게 됨
	// print(10); 
	// 3. 암묵적인 형 변환이 아닌 명시적으로 형 변환을 표기한 케이스
	print(Widget(10));

}