#include <iostream>
using namespace std;
int main() {
	int* p = NULL;
	p = new int{12}; // 동적 메모리 할당 및 초기화
	// {} , () : 값을 초기화
	// { } : 타입 검사를 진행
	// ( ) : 타입이 정확하지 않아도 형 변환 진행됨
	if (p == NULL) {
		cout << "동적 메모리 할당 실패\n";
		return 1;
	}

	cout << "정수를 입력하세요: ";
	// 아래의 cin 이 없는 경우 그 아래 cout 에서 12 가 출력됨 !
	cin >> *p; // 동적 메모리 사용( + cin 에서 p 가 아닌 *p 실제 변수 값 그대로 적용)
	cout << "입력된 정수는 " << p[0] << "\n"; // 동적 메모리 사용
	delete p; // 동적 메모리 해제
	p = NULL;

	// 동적 메모리 배열
	int num;
	cin >> num; // 마찬가지로 주소가 아닌 실제 변수 값 그대로 cin 에 받음
	int* data = new int[num]; // 동적 메모리 할당, [] : 개수
	for (int i = 0;i < num;i++) {
		cout << "(배열) 정수를 입력하세요: ";
		cin >> data[i];
	}
	delete[] data; // 동적 메모리 해제
	
	// nullptr : ptr 변수가 NULL 일 경우
	// ex. if(p==NULL) 대신에 if(p == nullptr) 사용

	// 해제 delete 후 nullptr 로 만들어주는 것이 더 좋음.
	data = nullptr; // == data = NULL;
	
	return 0;
}