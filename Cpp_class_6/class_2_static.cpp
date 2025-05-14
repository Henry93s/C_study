/*
	static 
	- 정적 멤버 변수 : 같은 클래스 객체들 사이에 공유되는 멤버 변수
	- 정적 멤버 함수 : 객체 없이 클래스 이름으로 접근하여 호출할 수 있는 멤버 함수
		* 객체 생성과 관계없이 프로그램이 생성될 때 한번만 생성되고 프로그램이 종료될 때 소멸
		* 프로그램 전체 영역에서 하나만 존재하는 멤버
		* 특정 객체 소유가 아니라 클래스의 소유이므로 클래스 이름(::) 으로 접근이 가능하다.	
		* static 멤버는 public 이어야 외부에서 직접 접근이 가능
		* ! 정적 멤버는 클래스에서 선언하고 전역에서 초기화한다.
		* ! 정적 멤버 함수는 정적 멤버 변수, 정적 멤버 함수만 직접 사용 가능
		* ! 정적 멤버 함수는 객체 없이 호출되기 때문에 this 가 없다.

	singleton pattern
	- static 변수를 사용하여 객체가 1번만 생성되도록 하는 디자인 패턴
	=> 해당 인스턴스에 대해 전역 접근을 허용
*/
#include <iostream>
using namespace std;
class SoSimple {
private: // static 맴버 변수는 public 이어야 외부에서 직접 접근이 가능 !
public:
	static int simObjCnt; // static 맴버변수(클래스 변수)
	static int xScreen, yScreen;

	// mutable : const 함수 내 에서 멤버의 변경이 가능하도록 함
	mutable int zScreen;
	
	// const static 멤버 변수 : 클래스가 정의될 때 지정된 값으로 유지되는 상수
	// * static 변수 이지만 const 이므로 선언과 동시에 초기화가 이루어짐
	const static int YEAR = 2025;
public:
	SoSimple() {
		simObjCnt++;
		this->zScreen = 0;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
	void printZ() {
		cout << "const method 에서 mutable 변수의 변경 적용 확인" << endl;
		cout << this->zScreen << endl;
	}

	// static 멤버 함수
	static void SetXYScreen(int x, int y) {
		// xScreen, yScreen : 모두 static 변수이기 때문에 static 멤버 함수에서 사용 가능
		xScreen = x;
		yScreen = y;
	}
	static void printXY() {
		cout << "static 멤버 함수를 통해 변경하고 적용 확인 + const static 값도 확인" << endl;
		cout << YEAR << "년 " << xScreen << ", " << yScreen << endl;
	}

	// const method : 해당 메소드 내에서의 변경은 발생하지 않아야 함
	void setZScreen(int z) const { 
		// zScreen 은 mutable 변수이기 때문에 const 메소드 내에서 변경이 가능함
		zScreen = z;
	}
};

int SoSimple::simObjCnt = 0; // static 멤버변수 초기화
int SoSimple::xScreen = 0;
int SoSimple::yScreen = 0;

int main() {
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	SoSimple sim1;
	SoSimple sim2;
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;

	// static 멤버 함수를 통해 변경하고 적용 확인
	// + const static 멤버 변수 확인
	SoSimple::SetXYScreen(1, 2);
	SoSimple::printXY();

	// const method 에서 mutable 변수의 변경 적용 확인
	sim1.setZScreen(100);
	sim1.printZ();

	return 0;
}
