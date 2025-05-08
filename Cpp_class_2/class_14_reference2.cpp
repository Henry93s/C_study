#include <iostream>
using namespace std;

int main(void){
    int val1 = 100;
    int& val2= val1;
    // int& val3 = 200; // 참조자 선언 시 변수에 붙이지 않음
    int& val4 = val2;
    // int& val5; // 초기화하지 않음
    val1 = val1 * 3;
    cout << "val1 = " << val1 << endl; // 300
    cout << "val2 = " << val2 << endl; // 300
    cout << "val3 = " << val4 << endl; // 300

    return 0;
}
