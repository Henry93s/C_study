#include <iostream>
using namespace std;

int main() {
	int arr[5] = { 0,1,2,3,4 };
	// 전체 배열을 순회하므로 배열의 길이를 작성할 필요없음
	// iterator : 대상배열 로 범위기반 for 문 작성
	for (int i : arr) {
		cout << i << " ";
	}
	cout << endl;

	// int 대신에 auto 를 사용할 수도 있음
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}