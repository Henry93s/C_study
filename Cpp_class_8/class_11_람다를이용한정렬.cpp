#include <iostream>
#include <algorithm> // sort 함수에 사용
#include <vector>

using namespace std;

class Multiplier {
	int first;
	int second;

public:
	Multiplier(int f, int s) {
		first = f;
		second = s;
	}

	int getResult() {
		return first * second;
	}
};

int main() {
	vector<Multiplier> multipleData;

	for (int i = 0;i < 10;i++) {
		// rand() % 10 : 0 ~ 9 까지 랜덤 수 반환
		Multiplier multiple = Multiplier(rand() % 10, rand() % 10);
		multipleData.push_back(multiple);
	}

	cout << "정렬되지 않은 결과" << endl;
	// auto == vector<Multiplier>::iterator
	for (vector<Multiplier>::iterator iter = multipleData.begin();
		iter != multipleData.end();iter++) {
		cout << iter->getResult() << " ";
	}

	sort(multipleData.begin(), multipleData.end(), [](Multiplier& m1, Multiplier& m2) {
		// lambda 를 이용한 비교함수 선언
		return m1.getResult() < m2.getResult();
		});
	
	cout << endl;
	cout << "정렬된 결과" << endl;
	// auto == vector<Multiplier>::iterator
	for (auto iter = multipleData.begin(); iter != multipleData.end();iter++) {
		cout << iter->getResult() << " ";
	}
	cout << endl << endl;
	// 직전 for 문을 for_each 로 변경
	for_each(multipleData.begin(), multipleData.end(), [=](Multiplier iter) {
		cout << iter.getResult() << " ";
		});
	cout << endl;
	
	return 0;
}

