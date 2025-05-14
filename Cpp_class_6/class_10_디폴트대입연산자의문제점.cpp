#include <iostream>
using namespace std;

class Person {
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}
	void ShowPersonInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person() {
		delete[] name;
		cout << "called destructor!" << endl;
	}

	// 디폴트 복사 생성자 (=) 로 복사(얕은 복사)하고 소멸했을 때 
	// man1 delete 후 man2 delete 시 이미 삭제 됐으므로 에러 발생
	// => 해결 : operator= 대입 연산자 오버로딩을 사용하여 깊은 복사로 복사함.
	Person& operator=(const Person& ref) {
		delete[] name;
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy_s(name, len, ref.name);
		age = ref.age;
		return *this;
	}
};

int main() {
	Person man1((char*)"Lee dong woo", 29);
	Person man2((char*)"Yoon ji yul", 22);
	man2 = man1; //
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	// man1 소멸자 실행
	// man2 소멸자 실행 (깊은 복사로 생성됐을 때 에러가 발생하지 않음)

	return 0;
}