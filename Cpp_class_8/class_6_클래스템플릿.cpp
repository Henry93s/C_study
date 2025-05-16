/*
	클래스 템플릿 : 클래스 "내" 사용되는 자료형을 제네릭(일반화) 타입으로 작성
	"클래스 템플릿" 선언 = template <typename T>
							class MyArray {
	"템플릿 클래스" 선언 = MyArray<int> array1;
	"템플릿 클래스 멤버 함수 정의"
		template <typename T>
		void MyArray<T>::add_list(const T& element)
*/
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

// 템플릿 클래스 멤버 함수 정의
template <typename T>
void MyArray<T>::add_list(const T& element) {
	list.push_back(element);
}
// 템플릿 클래스 멤버 함수 정의
template <typename T>
void MyArray<T>::delete_last_list() {
	list.pop_back();
}
// 템플릿 클래스 멤버 함수 정의
template <typename T>
void MyArray<T>::show_list() {
	cout << "[MyArray list look up]" << endl;
	// iterator : STL 에서 항목들을 순환할 때 사용
	// typename vector<T>::iterator 대신 auto 를 자주 사용(훨씬 짧음)
	for (typename vector<T>::iterator i = list.begin();i != list.end(); ++i) {
		cout << *i << endl;
	}
}

int main() {
	// "템플릿 클래스" 선언
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