#include <iostream>
using namespace std;
class MyProfile {
private:
	int* ptrNum;
	int zipcode;
public:
	MyProfile(int n, int zc) {
		ptrNum = new int;
		*ptrNum = n;
		zipcode = zc;
		cout << "생성자 실행" << endl;
	}

	// 자동으로 삽입되는 디폴트 복사 생성자(과정을 보기 위해 c out 문을 작성하여 커스텀함)
	/*
	MyProfile(const MyProfile& copy) : ptrNum(copy.ptrNum), zipcode(copy.zipcode) {
		// ptrNum 에서 얕은 복사 발생
		// 얕은 복사 : 포인터 변수를 복사하여 주소만 복사되는 것
		// (깊은 복사 : 포인터 변수가 가리키는 데이터를 복사하는 것)
		cout << "ptrnum을 얕은 복사를 통해 MyProfile2 가 생성되었음" << endl;
	}
	*/
	// 얕은 복사 문제 해결 -> ptrNum 을 다시 새로 메모리 할당하고, 값을 저장한다.
	
	MyProfile(const MyProfile& copy) : zipcode(copy.zipcode) {
		// (깊은 복사 : 포인터 변수가 가리키는 데이터를 복사하는 것)
		ptrNum = new int;
		*ptrNum = *copy.ptrNum;
		cout << "ptrnum을 깊은 복사를 통해 MyProfile2 가 생성되었음" << endl;
		// 깊은 복사를 적용하여 MyProfile2 를 생성하면 return 전에 정상적으로 두 개의 객체를 소멸한다.
	}
	
	void setProfile(int n, int zc) {
		*ptrNum = n;
		zipcode = zc;
	}
	void getProfile() {
		cout << "ptrNum: " << ptrNum << endl;
		cout << "*ptrNum: " << *ptrNum << endl;
		cout << "zipcode: " << zipcode << endl;
		cout << endl;
	}

	~MyProfile() {
		delete ptrNum;
		cout << "소멸자 실행" << endl;
	}
};

int main() {
	MyProfile profile1(10, 90031);
	profile1.getProfile();

	// 복사 생성자 : CASE 1. 이미 만들어진 객체를 통해 객체를 "초기화" 하는 생성자
	// 복사 생성자로 인해 멤버 대 멤버 "값" 의 복사가 일어난다.
	MyProfile profile2(profile1); // 복사 생성자를 통해 "값" 복사가 발생
	// 이 때 ptrnum 의 경우 주소값을 그대로 가져오게됨. => "얕은 복사"

	profile1.getProfile();
	profile2.getProfile();
	profile2.setProfile(500, 90000);
	profile1.getProfile(); 
	// 얕은 복사로 profile2 생성 : 500, 90031
	// 깊은 복사로 profile2 생성 : 10, 90031

	profile2.getProfile(); // 500, 90000

	// 자동으로 생성된 소멸자 실행에서 profile1 을 소멸하고, profile2를 소멸하려는데
	// profile2 의 멤버 ptrnum 이 가리키는 profile1 의 ptrnum 은 이미 소멸되어
	// ==> 런타임 에러가 발생함 !!	
	return 0;
}