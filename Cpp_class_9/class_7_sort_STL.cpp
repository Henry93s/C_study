#include <iostream>
#include <vector>
#include <algorithm> // sort 시 필수 헤더 파일
using namespace std;

int main() {
	int arr[10] = { 97,44,23,55,61,12,3,75,27,84 };
	cout << "정렬된 배열 : ";
	sort(arr, arr + 10); // index 기준으로 9가 아니라 개수 10 N 그대로 삽입

	for (int i = 0;i < 10;i++) {
		cout << *(arr + i) << endl;
	}
	cout << endl;

	vector<string> strings;
	string s;
	cout << "문자열을 입력하세요 : ";
	while (cin >> s) {
		strings.push_back(s);
	}

	sort(strings.begin(), strings.end());
	cout << "정렬된 문자열 : ";
	for (vector<string>::iterator it = strings.begin();it != strings.end();it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}