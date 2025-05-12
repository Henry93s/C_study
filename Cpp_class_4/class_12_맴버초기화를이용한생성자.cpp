#include <iostream>
#include <string.h>
using namespace std;

enum {
    NAME_LEN = 20,
    SEX_LEN = 10,
    JOB_LEN = 20,
    CHARACTER_LEN = 20
};

class Chulsoo {
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;
public:
    Chulsoo(const char* name, const char* sex, const char* job, const char* character, int age, bool marriageStatus) {
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriageStatus = marriageStatus;
    }
    Chulsoo() {
        cout << "Chulsoo() 생성자 완료" << endl;
    }
    void introduce() {
        cout << "이름 : " << name << endl;
        cout << "성별 : " << sex << endl;
        cout << "직업 : " << job << endl;
        cout << "캐릭터 : " << character << endl;
        cout << "나이 : " << age << endl;
        cout << "결혼여부 : " << (marriageStatus ? "YES" : "NO") << endl;
    }
    void eat(const char* food) {
        cout << "철수는 " << food << "먹는다." << endl;
    }
    void sleep() {
        cout << "철수는 잔다." << endl;
    }
    void drive(const char* destination) {
        cout << destination << "으로 운전해라" << endl;
    }
    void write() {
        cout << "철수는 책을 쓴다" << endl;
    }
    void read() {
        cout << "철수는 책을 읽는다." << endl;
    }
};

class Younghee {
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;
public:
    Younghee(const char* name, const char* sex, const char* job, const char* character, int age, bool marriageStatus) {
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriageStatus = marriageStatus;
    }
    Younghee() {
        cout << "Younghee() 생성자 완료" << endl;
    }
    void introduce() {
        cout << "이름 : " << name << endl;
        cout << "성별 : " << sex << endl;
        cout << "직업 : " << job << endl;
        cout << "캐릭터 : " << character << endl;
        cout << "나이 : " << age << endl;
        cout << "결혼여부 : " << (marriageStatus ? "YES" : "NO") << endl;
    }
    void eat(const char* food) {
        cout << "영희는 " << food << "먹는다." << endl;
    }
    void sleep() {
        cout << "영희는 잔다." << endl;
    }
    void drive(const char* destination) {
        cout << destination << "으로 운전해라" << endl;
    }
    void write() {
        cout << "영희는 책을 쓴다" << endl;
    }
    void read() {
        cout << "영희는 책을 읽는다." << endl;
    }
};

// 멤버 초기화를 이용한 생성자
class DailyLife {
private:
    Chulsoo chulsoo; // 객체를 private 맴버로 가짐
    Younghee younghee; // 객체를 private 맴버로 가짐
public:
    // chulsoo 와 younghee 객체를 받아서 dailylife 의 맴버를 초기화하였음.
    DailyLife(Chulsoo chulsooObject, Younghee youngheeObject) {
        cout << "DailyLife::DailyLife(chulsooObject, youngheeObject) 생성자 시작" << endl;
        chulsoo = chulsooObject;
        younghee = youngheeObject;
        cout << "DailyLife::DailyLife(chulsooObject, youngheeObject) 생성자 완료" << endl;
    }
    // 기본 생성자를 사용하지 않으려면, 초기화 리스트를 사용하여 직접 맴버 객체를 초기화한다.
    /*
    DailyLife(Chulsoo chulsooObject, Younghee youngheeObject)
        : chulsoo(chulsooObject), younghee(youngheeObject) { // 초기화 리스트 사용
        cout << "DailyLife::DailyLife(chulsooObject, youngheeObject) 생성자 완료" << endl;
    }
    */
    void run() {
        chulsoo.drive("레스토랑");
        chulsoo.eat("스테이크");
        younghee.eat("스테이크");
        chulsoo.drive("집");
        younghee.sleep();
        chulsoo.write();
        chulsoo.read();
        chulsoo.sleep();
        cout << endl;
        chulsoo.introduce();
        cout << endl;
        younghee.introduce();
    }
};


int main(void) {
    Chulsoo chulsoo((char*)"철수", (char*)"남성", (char*)"작가", (char*)"diligent", 32, true);
    Younghee younghee((char*)"영희", (char*)"여성", (char*)"주부", (char*)"impatient", 32, true);

    // DailyLife 멤버 객체는 생성자 본문이 실행되기 전에 초기화되어야 하므로 
    // 각각 Chulsoo, Younghee 클래스에 기본 생성자가 호출되어야 한다.
    DailyLife dailylife(chulsoo, younghee);
    dailylife.run();

    return 0;
}