/*
	priority queue : 가장 큰 값을 신속하게 찾거나 제거할 필요가
	빈번하게 발생하는 상황에서 유용하게 사용되는 queue
	- <vector>, <queue> 헤더 파일 필요
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq2;
	priority_queue<int, deque<int>, greater<int>> pq3;

	pq.push(10);
	pq.push(20);
	pq.push(30);
	pq.push(40);
	pq.push(40);
	pq.push(10);
	pq.push(20);

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq2.push(pq.top());
		pq.pop();
	}

	cout << endl;

	while (!pq2.empty()) {
		cout << pq2.top() << " ";
		pq3.push(pq2.top());
		pq2.pop();
	}

	cout << endl;

	while (!pq3.empty()) {
		cout << pq3.top() << " ";
		pq3.pop();
	}

	cout << endl;

	return 0;


}