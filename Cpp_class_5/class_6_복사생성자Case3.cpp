#include <iostream>
using namespace std;
class SoSimple {
private:
	int num;
public:
	SoSimple(int n) : num(n) {
		cout << "생성자를 통해 생성되었음" << endl;
	}

	SoSimple(const SoSimple& copy) : num(copy.num) {
		cout << "복사 생성자를 통해 생성되었음" << endl;
	}

	void ShowData() {
		cout << num << endl;
	}

	SoSimple& AddNum(int n) { // 객체를 반환하되 참조형으로 반환하지 않는 멤버 함수
		num += n;
		return *this;
	}
};

// 복사 생성자
// CASE 3. : 객체를 반환하되 참조형으로 반환하지 않는 경우
SoSimple SimpleFuncObj(SoSimple obj) { 
	// 매개변수에 객체로 인해 내부 동작에서 CASE 2 를 포함함 !
	cout << "return 이전" << endl;
	// 반환 시점에서 함수 내 지역 변수인 임시 객체가 소멸되므로 
	// return 시 복사 생성자를 통해 생성 후 반환됨
	return obj; 
}
int main() {
	SoSimple sim1(10);
	cout << "SimpleFuncObj 함수호출 전" << endl;

	// 복사 생성자
	// CASE 3. : 객체를 반환하되 참조형으로 반환하지 않는 경우
	SimpleFuncObj(sim1).AddNum(10).ShowData(); // 20 : "임시 객체"에서의 연산 결과
	// 다음 문장에서 "임시 객체" 는 자동 소멸됨
	// sim1 = SimpleFuncObj(sim1).AddNum(10); 을 수행했다면 아래 showData 에서 20 확인
	
	cout << "SimpleFuncObj 함수호출 후" << endl;
	sim1.ShowData(); // 10 : 기존 sim1 객체에서의 값 유지
	return 0;
}
/*
	임시 객체 : 객체 없이 생성자를 호출할 때 생성됨
		- 다음 문장으로 넘어가려고 할 때 자동으로 소멸
		- return 값 : 임시 객체의 reference 값
*/