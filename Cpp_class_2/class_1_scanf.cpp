#include <iostream>
// using namespace std; 네임스페이스 선언을 하지 않았기 때문에 cin, cout 사용 시 std 네임스페이스 별도 지정이 필요
int main(void){
    int val1;
    std::cout<<"첫 번째 숫자입력: ";
    std::cin>>val1;

    int val2;
    std::cout<<"두 번째 숫자입력: ";
    std::cin>>val2;

    int result = val1+val2;
    std::cout<<"덧셈결과: "<<result<<std::endl;

    return 0;
}
