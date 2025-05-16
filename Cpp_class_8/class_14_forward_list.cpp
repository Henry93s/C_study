// forward_list : 단방향 리스트
// 양방향 리스트보다 메모리 사용을 덜하기 때문에 속도가 약간 더 빠르다
#include <iostream>
#include <forward_list>
using namespace std;

int main() {
	forward_list<int> fl;
	forward_list<int> fl2 = { 1,2,3,4 };

	fl.push_front(10);
	fl.push_front(20);
	fl.push_front(30);
	fl.push_front(40);

	for (auto i = fl.begin();i != fl.end();i++) {
		cout << *i << " ";
	}
	cout << endl;

	for (auto i = fl2.begin();i != fl2.end();i++) {
		cout << *i << " ";
	}
	cout << endl;

	for (auto i = fl.begin();i != fl.end();i++) {
		if (*i == 30) {
			fl.splice_after(i, fl2);
			break;
		}
	}
	for (auto i = fl.begin();i != fl.end();i++) {
		cout << *i << " ";
	}
	cout << endl;
	
	forward_list<int> fl3 = { 100,200,300,400 };
	auto p = fl.before_begin();
	// 한 리스트 요소를 다른 리스트 해당 위치 "뒤" 로 삽입
	fl.splice_after(p, fl3);

	for (auto i = fl.begin();i != fl.end();i++) {
		cout << *i << " ";
	}
	cout << endl;

	return 0;
}