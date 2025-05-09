#include <iostream>
using namespace std;

// 함수 선언부를 별도로 둘 때에는 선언부에서 디폴트 매개변수 지정
int BoxVolume(int length, int width = 1, int height = 1); 

int main(void) {
	cout << "[3,3,3] : " << BoxVolume(3, 3, 3) << endl; // 27
	cout << "[5,5,D] : " << BoxVolume(5, 5) << endl; // 5*5*1 = 25
	cout << "[7,D,D] : " << BoxVolume(7) << endl; // 7*1*1 = 7
	
	// cout << "[D,D,D] : " << BoxVolume() << endl; // error : int length는
	// 디폴트 매개변수가 아니므로 매개변수를 전달해주어야 함!

	return 0;
}

// 함수 정의부에서는 선언부에서 지정한 디폴트 매개변수를 지정하지 않음
int BoxVolume(int length, int width, int height) { 
	return length * width * height;
}