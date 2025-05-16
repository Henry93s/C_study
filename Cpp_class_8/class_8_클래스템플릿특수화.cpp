#include <iostream>
#include <vector>
using namespace std;

// "클래스 템플릿" 선언
template <typename T>
class MyArray {
private:
	vector<T> list;
public:
	void add_list(const T&);
	void delete_last_list();
	void show_list();
};

template <typename T>
void MyArray<T>::add_list(const T& element) {
	list.push_back(element);
}
template <typename T>
void MyArray<T>::delete_last_list() {
	list.pop_back();
}
template <typename T>
void MyArray<T>::show_list() {
	cout << "[MyArray list look up]" << endl;
	for (typename vector<T>::iterator i = list.begin();i != list.end(); ++i) {
		cout << *i << endl;
	}
}

// 클래스 템플릿 특수화
// "클래스 템플릿" 선언
template <>
class MyArray<int> {
private:
	vector<int> list;
public:
	void add_list(const int&);
	void delete_last_list();
	void show_list();
};

void MyArray<int>::add_list(const int& element) {
	list.push_back(element);
}

void MyArray<int>::delete_last_list() {
	list.pop_back();
}

void MyArray<int>::show_list() {
	cout << "[MyArray list look up (특수화)]" << endl;
	for (typename vector<int>::iterator i = list.begin();i != list.end(); ++i) {
		cout << *i << endl;
	}
}

int main() {
	// 특수화 클래스 선언 및 사용
	MyArray<int> array1;
	array1.add_list(1);
	array1.add_list(2);
	array1.add_list(3);
	array1.add_list(4);
	array1.add_list(5);
	array1.show_list();

	array1.delete_last_list();
	array1.delete_last_list();
	array1.show_list();

	MyArray<double> array2;
	array2.add_list(1.1);
	array2.add_list(2.2);
	array2.add_list(3.3);
	array2.add_list(4.4);
	array2.add_list(5.5);
	array2.show_list();

	array2.delete_last_list();
	array2.delete_last_list();
	array2.show_list();

	return 0;
}