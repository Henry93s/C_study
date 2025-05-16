/*
	vector : "동적 메모리 할당" 을 위한 컨테이너로 array 를 대체
	.at 함수 : 예외처리에 사용하여 boundary check, 초기화 여부를 체크함
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(6, 1);
	cout << "v.capacity(): " << v.capacity() << " / v.size(): "
		<< v.size() << endl;
	for (auto i = 0;i < v.size();i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;

	v.assign(4, 3);
	// assign 으로 사이즈를 줄여서 할당해도 capacity 는 줄어들지 않음
	cout << "v.capacity(): " << v.capacity() << " / v.size(): "
		<< v.size() << endl;
	for (auto i = 0;i < v.size();i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;

	v[2] = 7;
	for (vector<int>::iterator it = v.begin() + 3;it != v.end();it++) {
		*it = 9;
	}
	v.push_back(10);
	v.push_back(20);
	cout << "v.capacity(): " << v.capacity() << " / v.size(): "
		<< v.size() << endl;
	for (auto i = 0;i < v.size();i++) {
		cout << v[i] << " " ;
	}
	cout << endl << endl;

	v.push_back(30);
	cout << "v.capacity(): " << v.capacity() << " / v.size(): "
		<< v.size() << endl;
	for (auto i = 0;i < v.size();i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;

	v.resize(17);
	cout << "v.capacity(): " << v.capacity() << " / v.size(): "
		<< v.size() << endl;
	for (auto i = 0;i < v.size();i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;

	return 0;
}