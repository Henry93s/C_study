/*
	단항 연산자에 대한 연산자 오버로딩 함수는 인자 없이 사용하나,
	전역변수로 사용할 때는 인자를 하나 추가함
*/
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

	// 증감 연산자 오버로딩 함수 ++ 선언 및 정의 (전위증가)
	// 자기 자신의 데이터를 변경하므로 & 레퍼런스 객체를 반환한다.
	Point& operator++() {
		xpos += 1;
		ypos += 1;
		return *this;
		// 레퍼런스 객체를 반환하므로 *this; 
		// => (this 가 가리키는 객체의 주소로 본인의 값을 반환해야 하므로 * 추가)
	}

	// 증감 연산자 오버로딩 함수 (후위증가)
	// 
	// 단순히 후위증가임을 표시하기 위해 인자를 "인자 이름을 제외" 하여 입력
	const Point operator++(int) {
		const Point retobj(xpos, ypos); // const 객체
		xpos += 1; // 실제 객체(pos) 값을 증감
		ypos += 1;
		return retobj; // 변경하기 전 복사본을 반환
	}

	// friend 증감 연산자 오버로딩 "전역" 함수 (전위감소) -- 정의
	friend Point& operator--(Point& ref);
	// friend 증감 연산자 오버로딩 "전역" 함수 (후위감소) -- 정의
	// 
	// 단순히 후위증가임을 표시하기 위해 인자를 "인자 이름을 제외" 하여 입력
	friend const Point operator--(Point& ref, int);
};

// friend 증감 연산자 오버로딩 "전역" 함수 (전위감소) -- 정의
// => 연산자 오버로딩 함수를 전역으로 사용하므로 인자가 필요함
Point& operator--(Point& ref) {
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

// friend 증감 연산자 오버로딩 "전역" 함수 (후위감소) -- 정의
// 
// => 연산자 오버로딩 함수를 전역으로 사용하므로 인자가 필요함
const Point operator--(Point& ref, int) {
	const Point retobj(ref); // 현재 ref 객체 값을 복사
	ref.xpos -= 1; // 실제 객체(pos) 값을 증감
	ref.ypos -= 1;
	return retobj; // 변경하기 전 복사본을 반환
}

int main() {
	Point pos(1, 2);
	++pos; // 전위 증감 연산자 오버로딩 사용
	pos.ShowPosition(); // 2,3
	--pos;
	pos.ShowPosition(); // 1,2
	++(++pos);
	pos.ShowPosition(); // 3,4
	--(--pos);
	pos.ShowPosition(); // 1,2
	pos.operator++(); // ++pos 와 같다.
	pos.ShowPosition(); // 2,3

	cout << endl;

	// 후위 증감 연산자 오버로딩 사용
	pos++;
	pos.ShowPosition(); // 3,4
	pos--;
	pos.ShowPosition(); // 2,3
	pos.operator++(99999); // pos++; 와 같다.
	pos.ShowPosition(); // 3,4

	// 후위 감소 friend 연산자 오버로딩 "전역" 함수 이므로 pos. 같은 멤버 표기 아님
	operator--(pos, 99999);

	return 0;
}