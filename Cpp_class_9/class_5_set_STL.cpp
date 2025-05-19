/*
	set : 트리 형태로 값의 순서를 유지하여 값들을 관리
	- 시간 복잡도 O(logn)
	- insert 시 값의 순서를 유지하기 위해 정렬 수행
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> s;
	pair<set<int>::iterator, bool> pr;
	s.insert(10);
	s.insert(30);
	s.insert(60);
	s.insert(20);
	s.insert(50);
	pr = s.insert(40); //40을 정렬된 위치에 삽입, pr.first는 40의 위치 반복자

	for (auto i = s.begin();i != s.end();i++) {
		cout << *i << " ";
	}
	cout << endl;

	s.insert(pr.first, 55); // 55를 정렬된 위치에 삽입 (hint로 40의 위치를 제공)
	s.erase(pr.first); // 40의 위치(데이터 40) 삭제
	for (auto i = s.begin();i != s.end();i++) {
		cout << *i << " ";
	}
	cout << endl;

	auto f = s.find(55);

	if (f != s.find(55)) {
		cout << *f << endl;
	}

	// multiset
	multiset<int> ms;
	multiset<int>::iterator ms_iter;
	ms.insert(10);
	ms.insert(30);
	ms.insert(60);
	ms.insert(20);
	ms.insert(50);
	ms.insert(40);
	ms_iter = ms.insert(40);

	cout << endl;
	for (auto i = ms.begin();i != ms.end();i++) {
		cout << *i << " ";
	}
	cout << endl;


	return 0;
}