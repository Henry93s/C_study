#include <iostream>

namespace BestComImpl{
void SimpleFunc(void);
void PrettyFunc(void);
}

namespace ProgComImpl {
void SimpleFunc(void);
void PrettyFunc(void);
}

int main(){
    // 같은 이름이 정의되어 있을 때 이를 네임스페이스로 구분지어 놓아 사용할 수 있다.
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
}

// 네임스페이스 정의와 네임스페이스 내부 요소 정의를 분리함
void BestComImpl::SimpleFunc(void){
    std::cout<<"func is defined BestCom"<<std::endl; // BestCom 이 정의된 함수
    PrettyFunc(); // 내부 네임스페이스에서 호출할 함수를 찾음
    ProgComImpl::PrettyFunc(); // 외부 ProgComImpl 네임 스페이스 에서 호출할 함수를 찾음
}

void ProgComImpl::SimpleFunc(void){
    std::cout<<"\nfunc is defined ProgCom"<<std::endl; // ProgCom 이 정의된 함수
}

void BestComImpl::PrettyFunc(void){
    std::cout<<"Best Pretty"<<std::endl;
}

void ProgComImpl::PrettyFunc(void){
    std::cout<<"Prog Pretty"<<std::endl;
}
