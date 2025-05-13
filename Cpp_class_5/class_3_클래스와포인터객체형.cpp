#include <iostream>
using namespace std;
class MyProfile {
private:
	string name;
public:
	MyProfile(string n) {
		name.append(n); // string 함수 append, clear
	}
	void setName(string n) {
		name.clear();
		name.append(n);
	}
	void getName() {
		cout << "name: " << name << endl;
	}
};

int main() {
	MyProfile profile1("allen"); 
	profile1.getName();

	MyProfile* ptrProfile1 = new MyProfile("andrew"); // 동적 메모리 할당으로 객체 생성
	ptrProfile1->getName();
	delete ptrProfile1;

	cout << &profile1 << endl; // 서로 주소가 다름
	cout << &ptrProfile1 << endl;

	return 0;
}