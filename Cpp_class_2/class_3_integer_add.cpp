// 두 수 사이의 정수 합
#include <iostream>
int main(void){
    int val1, val2;
    int result =0;
    std::cout<<"input two integer: ";
    std::cin>>val1>>val2; // 연이은 데이터 입력을 명령할 수 있음
    // cin : 스페이스 바, 엔터, 탭과 같은 공백을 통해서 데이터 구분이 이뤄진다(== c에서의 scanf와 유사)

    if(val1<val2){
        for(int i=val1+1;i<val2;i++){
            result+=i;
        }
    }
    else {
        for(int i=val2+1;i<val1;i++){ // for 문 안에서 변수 선언 가능
            result+=i;
        }
    }
    std::cout<<"add integer between : "<<result<<std::endl;

    return 0;
}
