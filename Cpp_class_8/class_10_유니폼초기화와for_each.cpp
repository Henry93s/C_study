/*
	유니폼 초기화 : C++11 에서 신규로 추가된
		여러 객체를 동시에 생성하려고 할 때 사용
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
private:
	int age;
	string name;

public:
	Person(const int a, const string& n) : age(a), name(n) {}
	int getAge() { return age; }
	string getName() { return name; }
};

int main() {
	// c++ 03 ver
	Person p1{ 20, "Tom" };
	Person p2{ 19, "Jane" };

	// c++ 11 이상 ver 유니폼 초기화 적용
	vector<Person> vec{
		{21, "Smith"}, {39, "John"}, {23, "Mary"}, {45, "Ted"}
	};

	// for_each 문 (시작, 끝, "함수 또는 객체")
	// [](Person p) Person 객체의 값을 p 한 개씩 복사하여 for_each 문에 넘김  
	for_each(vec.begin(), vec.end(), [](Person p) {
		cout << p.getAge() << ", " << p.getName() << endl;
		});

	return 0;
}