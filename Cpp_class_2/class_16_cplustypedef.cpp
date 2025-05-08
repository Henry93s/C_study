#include <iostream>
using namespace std;
int main(){
    // typedef [자료형] [별칭]
    // 과 유사하게 C ++ 에서는 using [별칭] = [자료형] 로 사용

    using salary = double; // double 형에 salary 라는 별칭 선언
    using point = int; // int 형에 point 라는 별칭 선언

    salary youngjin = 125.20; // 변수를 salary 형으로 선언하고 초기화
    salary chris = 100.12;
}
