#include <iostream>
using namespace std;
void foo(int &ref);
// 레퍼런스의 용도 : 변수의 이름을 다른 함수 등등 경우에서 직접 사용할 수 없는 경우 사용.
int main(){
    int x= 10; // foo 함수에서는 main 자동 변수(지역 변수)인 x 를 사용할 수 없음
    foo(x);
    cout << "x = " << x << endl; // 11

    return 0;
}

void foo(int &ref){// 인자로 x 의 별명인 ref 전달
    ref++; // ref는 x 의 별명이므로 main 함수 의 x 가 증가함
}
