#include <iostream>

namespace BestComImpl{
void SimpleFunc(void){
    std::cout<<"func is defined BestCom"<<std::endl; // BestCom 이 정의된 함수
}
}

namespace ProgComImpl {
void SimpleFunc(void){
    std::cout<<"func is defined ProgCom"<<std::endl; // ProgCom 이 정의된 함수
}
}

int main(){
    // 같은 이름이 정의되어 있을 때 이를 네임스페이스로 구분지어 놓아 사용할 수 있다.
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
}
