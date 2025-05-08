// 네임스페이스 정의하고 사용하기
#include <iostream>
using namespace std;

// first 네임스페이스 정의
namespace first{
int value=1;
}

// second 네임스페이스 정의
namespace second{
int value =2;
}

int main(){
    cout << first::value<<endl; // 1 출력
    cout << second::value<<endl; // 2 출력
}
