// 펑터 : 

#include <iostream>
using namespace std;
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	// 전역함수로 연산자 오버로딩 함수를 정의하므로 friend 적용 ( << : cout )
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend Point operator+(const Point& source, const Point& source2);
};

Point operator+(const Point& source, const Point& source2) {
	Point point = Point(source.xpos + source2.xpos,
		source.ypos + source2.ypos);
	return point;
}

// 전역함수에서 << 연산자 오버로딩 함수 정의
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class Adder {
public:
	int operator()(const int& n1, const int& n2) {
		return n1 + n2;
	}
	double operator()(const double& e1, const double& e2) {
		return e1 + e2;
	}
	Point operator()(const Point& pos1, const Point& pos2) {
		return pos1 + pos2;
	}
};

int main() {
	Adder adder;
	cout << adder(1, 3) << endl;
	cout << adder(1.5, 3.7) << endl;
	cout << adder(Point(3, 4), Point(7, 9));

	return 0;
}