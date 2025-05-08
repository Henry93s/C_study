#include <iostream>
using namespace std;
int main() {
    int num = 10;
    int& ref = num; // ref 는 num 의 별명

    cout << "num= " << num << endl;
    cout << "ref= " << ref << endl; // num 출력

    ref = 100;

    cout << "num= " << num << endl; // 100
    cout << "ref= " << ref << endl; // 100

    cout << "&num= " << &num << endl; // 동일 주소
    cout << "&ref= " << &ref << endl; // 동일 주소

    return 0;
}
