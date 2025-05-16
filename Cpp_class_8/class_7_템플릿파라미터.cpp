/*
	템플릿 파라미터 : 템플릿 클래스 선언이나 템플릿 클래스 함수에
	파라미터를 전달하려고 할 때 사용한다.
*/
#include <iostream>
#include <vector>
using namespace std;

// int init : 템플릿 파라미터 적용
template <typename T, int init>
class MyArray {
private:
	vector<T> list;
public:
	MyArray() {
		for (int i = 0;i < init;i++)
			list.push_back(i);
	}
	void add_list(const T&);
	void delete_last_list();
	void show_list();
};


// int init : 템플릿 파라미터 적용
template <typename T, int init>
void MyArray<T, init>::add_list(const T& element) {
	list.push_back(element);
}
// int init : 템플릿 파라미터 적용
template <typename T, int init>
void MyArray<T, init>::delete_last_list() {
	list.pop_back();
}
// int init : 템플릿 파라미터 적용
template <typename T, int init>
void MyArray<T, init>::show_list() {
	cout << "[MyArray list look up]" << endl;
	// iterator : STL 에서 항목들을 순환할 때 사용
	// typename vector<T>::iterator 대신 auto 를 자주 사용(훨씬 짧음)
	for (typename vector<T>::iterator i = list.begin();i != list.end(); ++i) {
		cout << *i << endl;
	}
}

int main() {
	// int init : 템플릿 파라미터 적용
	MyArray<int, 3> array1;
	array1.show_list();

	array1.delete_last_list();
	array1.delete_last_list();
	array1.show_list();

	// int init : 템플릿 파라미터 적용
	MyArray<int, 4> array2;
	array2.show_list();

	array2.delete_last_list();
	array2.delete_last_list();
	array2.show_list();

	return 0;
}