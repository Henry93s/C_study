#include <iostream>
using namespace std;

class Widget {
public:
	// 사용자 정의 생성자로 인해 디폴트 생성자가 생성되지 않음
	Widget(int x, int y) : a(x + y) {}
	Widget() = default; // 명시적으로 default 키워드를 사용하여 
	// 디폴트 생성자가 생성되도록 함.
	
	int getvalue();
	void setvalue(int a = 1); // 디폴트 매개변수 적용
private:
	int a;
};
int Widget::getvalue() {
	return a;
}
void Widget::setvalue(int a) {
	this->a = a;
}

void print(Widget rhs) {
	cout << rhs.getvalue() << endl;
}

int main() {
	Widget w;
	w.setvalue(); // 클래스 정의에서 디폴트 매개변수로 인해 1로 set

	print(w);

	return 0;
}