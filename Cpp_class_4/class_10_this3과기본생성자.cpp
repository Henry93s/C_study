#include <iostream>
using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20

class Chulsoo {
private:
	char name[NAME_LEN];
	char sex[SEX_LEN];
	char job[JOB_LEN];
	char character[CHARACTER_LEN];
	int age;
	bool marriageStatus;

public:
	// 생성자 선언 및 정의
	Chulsoo(char* name, char* sex, char* job, char* character, int age,
		bool marriageStatus) {
		strcpy_s(this->name, name);
		strcpy_s(this->sex, sex);
		strcpy_s(this->job, job);
		strcpy_s(this->character, character);
		this->age = age;
		this->marriageStatus = marriageStatus;
	}

	void introduce() {
		cout << "이름: " << name << endl;
		cout << "성별: " << sex << endl;
		cout << "직업: " << job << endl;
		cout << "성격: " << character << endl;
		cout << "나이: " << age << endl;
		cout << "결혼여부: " << (marriageStatus ? "YES" : "NO") << endl;
	}

	void eat(char* food) {
		cout << "철수는 " << food << "를 먹는다" << endl;
	}
	void sleep() {
		cout << "철수는 잔다" << endl;
	}
	void drive(char* destination) {
		cout << "철수는 " << destination << "으로 운전한다" << endl;
	}
	void write() {
		cout << "철수는 책을 쓴다" << endl;
	}
	void read() {
		cout << "철수는 책을 읽는다" << endl;
	}
	
};

int main() {
	// 디폴트 생성자 : 클래스에서 기존 생성자 선언이 없을 때, 자동으로 추가된다.
	
	// 아래는 생성자에 따라 객체 생성
	Chulsoo chulsoo((char*)"철수", (char*)"남성", (char*)"작가", (char*)"diligent", 32, true);

	chulsoo.drive((char*)"레스토랑");
	chulsoo.eat((char*)"스테이크");
	chulsoo.drive((char*)"집");
	chulsoo.write();
	chulsoo.read();
	chulsoo.sleep();
	cout << endl;
	chulsoo.introduce();
	cout << endl;

	return 0;
}