/*

*/
#include <iostream>
#include <map>
using namespace std;
int main() {
	map<string, int> m;
	m.insert(make_pair("A", 10));
	m.insert(make_pair("B", 20));
	m.insert(make_pair("C", 30));
	m.insert(make_pair("D", 40));
	m.insert(make_pair("E", 50));
	m["F"] = 100; // m.insert(make_pair("F", 100));

	for (auto i = m.begin();i != m.end();++i) {
		cout << "[" << i->first << " " << i->second << "] ";
	}
	cout << endl;

	auto i = m.find("A"); // key "A" 위치 i
	cout << i->first << " : " << i->second << endl;
	
	m.insert(make_pair("E", 150)); // 이미 key 'E' 에는 value 50이 있어서 반영 X
	for (auto i = m.begin();i != m.end();++i) {
		cout << "[" << i->first << " " << i->second << "] ";
	}
	cout << endl;
	cout << endl;
	cout << endl;


	// m 이 multimap 이었을 경우, key 가 중복이어도 pair 및 insert 동작이 반영됨 !
	multimap<string, int> mm;
	mm.insert(make_pair("A", 10)); // make_pair 로 key, value 쌍을 만들고 만들어진 쌍을 insert
	mm.insert(make_pair("B", 20));
	mm.insert(make_pair("C", 30));
	mm.insert(make_pair("D", 40));
	mm.insert(make_pair("E", 50));

	mm.insert(make_pair("C", 100));
	mm.insert(make_pair("C", 200));

	for (auto i = mm.begin();i != mm.end();++i) {
		cout << "[" << i->first << " " << i->second << "] ";
	}
	cout << endl;

	auto lo_bo = mm.lower_bound("C"); // key 가 "C" 첫 번째 key, value 위치
	auto up_bo = mm.upper_bound("C"); // key 가 "C" 마지막 key, value 위치의 다음 위치
	cout << "key C의 value 들: ";
	for (auto i = lo_bo;i != up_bo;++i) {
		cout << "["  << i->second << "] ";
	}
	cout << endl;

	auto eq_ra = mm.equal_range("C"); // key 가 "C" 인 key,value 쌍 모음
	cout << "(또 다른 방법)key의 value 들: ";
	for (auto i = eq_ra.first;i != eq_ra.second;++i) {
		cout << "[" << i->second << "] ";
	}
	cout << endl;

	return 0;
}