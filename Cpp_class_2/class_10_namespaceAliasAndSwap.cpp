#include <iostream>

using namespace std;

namespace AAA{
namespace BBB{
namespace CCC{
int num1;
int num2;
}
}
}
void callByValue(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void callByReference(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(void){
    AAA::BBB::CCC::num1=10; // 기본적인 중첩된 네임스페이스의 변수 접근
    AAA::BBB::CCC::num2=20;

    namespace ABC = AAA::BBB::CCC; // 중첩된 구조의 네임스페이스를 묶어서 alias 별칭을 지정할 수 있다.
    cout << ABC::num1 << endl; // 10
    cout << ABC::num2 << endl; // 20

    cout << "callbyvalue swap" << endl;
    callByValue(ABC::num1, ABC::num2); // 매개변수에 값을 넘겨서 swap 시도
    cout << ABC::num1 << endl; // 10 // 변하지 않음
    cout << ABC::num2 << endl; // 20

    cout << "callByReference swap" << endl;
    callByReference(&ABC::num1, &ABC::num2); // 매개변수에 주소를 넘겨서 swap 시도
    cout << ABC::num1 << endl; // 20 // 주소가 가리키는 값을 swap 시켰으므로 값이 변경됨
    cout << ABC::num2 << endl; // 10

    return 0;
}
