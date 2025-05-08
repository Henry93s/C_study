#include <iostream>
using namespace std;
// decltype(declare type - 초기화 불필요) 변수
// : () 내부 결과에 따라 자동 자료형 할당
// 추가 : decltype((변수)) 선언할 변수 => reference 변수 !

int f() {
    return 20 + 30;
}

int main() {
    double d = 1.414;
    decltype(f()) decVar1 = d; // int 1
    decltype(d) decVar2 = decVar1; // double 1.414
    decltype((d)) decVar3 = decVar2; // double& decVar2 참조자(레퍼런스) 변수
    decVar2 = 3.141592;

    cout << decVar1 << " " << &decVar1 << endl; // 1, decVar1 의 주소
    cout << decVar2 << " " << &decVar2 << endl; // 3.14159, decVar2 의 주소
    cout << decVar3 << " " << &decVar3 << endl; // 3.14159, devVar2 의 주소

    return 0;
}
