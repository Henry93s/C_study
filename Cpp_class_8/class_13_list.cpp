#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> lt;
	list<int> lt2;
	lt.push_back(10);
	// 20 삽입 때 뒤에서 부터 삽입 하므로 20 30 
	lt.push_back(20);
	// 마찬가지로 뒤에서 부터 삽입하므로 10 20 30
	lt.push_back(30);
	lt.push_front(-10);
	// -20 삽입 때 앞에서 부터 삽입하므로 -20 -10
	lt.push_front(-20);
	// 마찬가지로 앞에서 부터 삽입하므로 -30 -20 -10
	lt.push_front(-30);

	for (auto i = lt.begin(); i != lt.end();i++) {
		cout << *i << " ";
	}
	cout << endl;

	for (auto i = 0;i < 10;i++) {
		lt2.push_back(i);
	}

	for (auto i = lt2.begin(); i != lt2.end();i++) {
		cout << *i << " ";
	}
	cout << endl;
		
	for (auto i = lt.begin(); i != lt.end();i++) {
		if (*i == 10) {
			// splice : 한 리스트 요소를 다른 리스트로 "이동"할 때 쓰임
			lt.splice(i, lt2);
			// lt 4번째 10 위치 앞에서 자르고 lt2 요소를 삽입
			break;
		}
	}
	for (auto i = lt.begin(); i != lt.end();i++) {
		cout << *i << " ";
	}
	cout << endl;
	
	return 0;
}