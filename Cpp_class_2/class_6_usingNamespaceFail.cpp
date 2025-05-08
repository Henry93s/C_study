#include <iostream>
using std::cout; // cout 로 범위를 좁혀 네임스페이스 지정
int main(){
    int i=0;
    cin >> i; // cin 은 지정하지 않았기 때문에 컴파일 에러 발생
    cout << i;
}
