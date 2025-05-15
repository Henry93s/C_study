/*
	unique_ptr : auto_ptr 을 대체한 포인터로 "하나"의 포인터만이 특정 객체를
		소유할 수 있도록 객체에 "소유권" 개념을 도입한 스마트 포인터
*/
#include <iostream>
#include <memory> // 스마트 포인터 사용 시 필수 라이브러리
using namespace std;
class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	Chulsoo() {
		cout << "Chulsoo::Chulsoo() 생성자 완료" << endl;
	}
	~Chulsoo() {
		cout << "Chulsoo::~Chulsoo() 소멸자 완료" << endl;
	}
	void introduce();
};

void Chulsoo::introduce() {
	cout << "철수 나이: " << age << endl;
}
using namespace std;
int main() {
	unique_ptr<Chulsoo> chulsooSmptr1(new Chulsoo(32));
	chulsooSmptr1->introduce();
	
	//cout << "unique_ptr<Chulsoo> 타입 간 복사 생성자 호출 후" << endl;
	// unique_ptr 은 "소유권" 때문에 인스턴스를 소유한 unique_ptr 동시 두개이상 불가
	// unique_ptr<Chulsoo> chulsooSmptr2 = chulsooSmptr1;
	
	cout << endl;

	cout << "unique_ptr<Chulsoo> Smptr2 로 \"소유권\" 이전 후" << endl;
	// Smptr2 로 "소유권" 이전
	unique_ptr<Chulsoo> chulsooSmptr2 = move(chulsooSmptr1);
	// == auto chulsooSmptr2 = move(chulsooSmptr1);
	
	// chulsooSmptr1->introduce(); 
	// Smptr1 introduce() 를 실행하고 아래를 실행할 경우 출력되지 않음
	// => 원인 : 
	// Smptr1 introduce() 를 주석처리하고 아래를 실행할 경우 출력됨
	chulsooSmptr2->introduce(); 

	chulsooSmptr1.reset(); // Smptr1 이 가리키고 있는 메모리 영역을 삭제
	chulsooSmptr2.reset(); // Smptr2 이 가리키고 있는 메모리 영역을 삭제
	 
	return 0;
}