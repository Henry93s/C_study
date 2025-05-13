/*
	 r-value reference
	: && 연산자를 통해 가능하며, 오직 r-value "임시 객체" 만을 참조하는 변수

	move : 실제로 객체를 복사시키지 않고, 인자로 넘어온 값을 r-value ref 로 캐스팅
	- == 소유권 이동 개념
	- => 값을 대입시킬 객체에는 r-value 레퍼런스를 넘겨서 메모리 주소를 그대로 전달
	- => 복사(copy) 를 피할 수 있어서, 메모리 및 시간 비용을 줄여 속도를 높일 수 있음.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string name1 = "allen";
	cout << "name1: " << name1 << endl;
	// name1 = 문자열 string "객체" -> r-value 이므로 r-value 레퍼런스를 넘겨서 메모리 주소를 그대로 전달
	string name2 = move(name1); 
	cout << "After, name2 = move(name1)" << endl;
	cout << "-> name1: " << name1 << endl; // name1 에서 name2 로 "이동" 됨
	cout << "-> name2: " << name2 << endl << endl;

	int zipcode1 = 90031;
	cout << "zipcode1: " << zipcode1 << endl;
	// zipcode1 = int 형 데이터 "변수" -> l-value 이므로 move 연산에서 값만 복사됨
	int zipcode2 = move(zipcode1); 
	cout << "After, zipcode1: " << zipcode1 << endl;
	cout << "-> zipcode1: " << zipcode1 << endl;
	cout << "-> zipcode2: " << zipcode2 << endl;

	return 0;
}
