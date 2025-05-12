#include <iostream>
using namespace std;
class Stack { // stack "클래스" "정의" ("정의" 시 멤버 변수가 메모리에 할당되지 않음)
private: // 보통 클래스 멤버(멤버 변수)는 데이터 은닉을 위해 private, protected 지정
	int m_size;
	int m_top;
	int* m_buffer; // 스택 요소들이 저장될 공간

public: // 멤버 함수는 public 지정
	void Initialize(int size = 10); // "default 매개변수"는 함수의 선언부에 지정 !
	void RemoveAll();
	bool Push(int value);
	bool Pop(int& value);
	void Print();

	// 접근자 함수
	// getter 함수
	int GetSize();
	int GetTop();
	bool GetData(int index, int& value);
	
	// setter 함수
	bool SetSize(int size = 20);
};
void Stack::Initialize(int size) {
	m_size = size;
	m_top = -1;
	m_buffer = new int[m_size]; // c++ "동적 메모리 할당"
	memset(m_buffer, 0, sizeof(int) * m_size); // 스택 공간을 size 만큼 0 으로 값을 초기화함
}
void Stack::RemoveAll() {
	m_size = 0;
	m_top = -1;
	delete[] m_buffer; // c++ 동적 메모리 해제
	m_buffer = NULL; // NULL 로 포인터가 가리키는 주소를 비워줌
}
bool Stack::Push(int value) {
	if (m_top >= m_size - 1) { // stack 공간을 초과해서 push 를 시도할 경우 false
		return false;
	} 
	m_buffer[++m_top] = value;
	return true;
}
bool Stack::Pop(int& value) {
	// int& value = value; 로 함수 내부에서 전달된 대상으로 초기화됨

	if (m_top < 0) { // stack 에 들어있는 값이 없을 때 pop 을 시도할 경우 false
		return false;
	}
	value = m_buffer[m_top--];
	return true;
}
void Stack::Print() {
	if (m_top < 0) {
		return;
	}
	for (int i = 0;i <= m_top;i++) {
		cout << m_buffer[i] << " ";
	}
	cout << "\n";
	return;
}
int Stack::GetSize() { // size 반환
	return m_size;
}
int Stack::GetTop() { // m_top index 반환
	return m_top;
}
bool Stack::SetSize(int size) {
	if (size < m_size) {
		return false;
	}
	int* tmp = m_buffer; // tmp 에 임시 저장
	m_size = size;
	m_buffer = new int[m_size]; // 새 사이즈로 동적 할당
	memcpy(m_buffer, tmp, sizeof(int) * (m_top + 1)); // 기존 임시 저장 배열을 cpy 로 복사
	delete[] tmp; // 복사 후 tmp 임시 저장 동적 할당 배열 메모리 해제
	return true;
}
bool Stack::GetData(int index, int& data) { // peek : 데이터를 가져오나 stack 에서 pop을 하지는 않음
	if (index < 0 || index > m_top) {
		return false;
	}
	data = m_buffer[index];
	return true;
}

int main() {
	// stack 동작 테스트
	Stack stack; // "정의된" Stack 클래스의 stack 객체 "생성" (생성 시 멤버 변수가 메모리에 할당)
	stack.Initialize(); // Initialize 멤버 함수가 "디폴트 매개변수"가 선언된 함수이므로
	// 10 개의 공간의 메모리를 동적 할당하고, 10개 size stack 을 0 으로 초기화됨.
	stack.Print();
	stack.Push(4);
	stack.Push(5);
	stack.Push(20);
	stack.Print();

	// Pop 함수의 매개변수가 "레퍼런스 변수"이므로 popvalue 변수를 
	// 전달해줄 때 Pop 함수 내부에서 변경되는 값이 main 함수에서도 반영됨
	int popValue;
	stack.Pop(popValue);
	cout << "pop value : " << popValue << endl;
	stack.Pop(popValue);
	cout << "pop value : " << popValue << endl;
	stack.Push(100);
	stack.Print();

	// 접근자 함수 사용
	int peekValue;
	cout << stack.GetSize() << endl;
	cout << stack.GetTop() << endl;
	stack.GetData(1, peekValue);
	cout << peekValue << endl;
	stack.SetSize();
	for (int i = 1;i < 11;i++) {
		stack.Push(i);
	}
	cout << stack.GetSize() << endl;
	stack.Print();


	// delete[] stack.m_buffer; // 컴파일 에러(접근 지정자가 private 으로 직접 접근 X)
	stack.RemoveAll(); // delete 로 메모리 할당 해제

	return 0;
}