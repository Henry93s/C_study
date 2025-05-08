#include <iostream>
using namespace std;
// auto (초기화 필요) 변수
// : 초기화한 변수와 동일한 자료형을 자동으로 할당 (자주 쓰임)
int main() {
    int n = 1234;
    double d = 1.231;

    auto autoVar1 = d; // double 형으로 자동 할당
    auto autoVar2 = n; // int 형 자동할당
    auto autoVar3 = n + d; // double 형 자동할당
    autoVar3 = 1.234;

    cout << autoVar1 << endl; // 1.231
    cout << autoVar2 << endl; // 1234
    cout << autoVar3 << endl; // 1.234

    return 0;
}
