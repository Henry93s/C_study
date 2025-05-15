#include <iostream>
using namespace std;
// 유도클래스 == 파생클래스
// -> 파생클래스 생성할 때,
// 부모 클래스로 디폴트 클래스 객체 생성자가 아닌 생성자로 
// 객체 생성이 필요할 때, 부모 클래스의 정의된 기초 클래스 생성자를 명시함

class SoBase {
private:
	int baseNum;
public:
	SoBase() : baseNum(20) {
		cout << "SoBase()" << endl;
	}
	SoBase(int n) : baseNum(n) {
		cout << "SoBase(n)" << endl;
	}
	void ShowBaseData() {
		cout << baseNum << endl;
	}
	// 소멸자 추가(소멸 과정 명시적 확인)
	~SoBase() {
		cout << "SoBase 소멸자 " << baseNum << endl;
	}
};

class SoDerived : public SoBase{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30) { // derivNum: 다음에 SoBase() 디폴트 생성자 생략됨
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) : derivNum(n) { // SoBase() 디폴트 생성자 생략됨
		cout << "SoDerived(n)" << endl;
	}
	SoDerived(int n1, int n2) : derivNum(n2), SoBase(n1) {
		// 디폴트 생성자가 없고, 의도한대로 부모클래스에 맞는 생성자로 
		// 객체 생성을 위해  부모클래스의 생성자를 따로 작성해야함
		cout << "SoDerived(int n1, int n2)" << endl;
	}
	void ShowDerivData() {
		ShowBaseData();
		cout << derivNum << endl;
	}

	// 소멸자 추가
	~SoDerived() {
		cout << "SoDerived 소멸자 " << derivNum << endl;
	}
};

int main() {
	cout << "case 1 ...." << endl;
	SoDerived dr1; // sobase(), soDerived()
	dr1.ShowDerivData(); // 20, 30
	cout << endl;
	cout << "case 2.... " << endl; 
	SoDerived dr2(12); // sobase(), soDerived(12)
	dr2.ShowDerivData(); // 20, 12
	cout << endl;
	cout << "case 3 ...." << endl;
	SoDerived dr3(23, 24); // sobase(23), soDerived(24)
	dr3.ShowDerivData(); // 23, 24
	
	return 0;
}