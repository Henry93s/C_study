// 네임스페이스의 범위 및 사용
#include "class_5_rectangleHeader.h"
#include "class_5_squareHeader.h"
using namespace square; // rectangle 또는 square 헤더 중 square 네임스페이스 사용

#include <iostream>

int main(){
    int y = x;
    std::cout<<y<<std::endl; // square 헤더에서 정의된 네임스페이스 내부 x 값 이 출력된다.
}
