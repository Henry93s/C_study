#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	// 디폴트 매개변수와 이니셜라이저를 적용한 생성자 선언 및 정의
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

	// 전역함수로 연산자 오버로딩 함수를 정의하므로 friend 적용 ( << : cout )
	friend ostream& operator<<(ostream& os, const Point& pos);
};

// 전역함수에서 << 연산자 오버로딩 함수 정의
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class BoundCheckPointArray {
private:
	Point* arr;
	int arrlen;

	// 복사 생성자와 대입 연산자를 private 에서 선언하여 데이터의 유일성을 보장
	// private 으로 선언 -> 디폴트 복사 / 디폴트 대입 연산자가 생성되지 않음
	BoundCheckPointArray(const BoundCheckPointArray& arr) {}
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) {}
public:
	BoundCheckPointArray(int len) : arrlen(len) {
		arr = new Point[len];
	}

	// 배열 클래스 : 배열 연산자 오버로딩을 통해 배열에 대한 경계 검사를 추가할 수 있음.
	Point& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	// const 도 함수 오버로딩의 조건이 된다.
	Point operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckPointArray() { delete[] arr; }
};

int main() {
	BoundCheckPointArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	for (int i = 0;i < arr.GetArrLen();i++) {
		cout << arr[i];
	}

	return 0;
}