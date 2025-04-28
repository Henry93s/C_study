// class_2-5.c : 실수값 비교 문제
#include <stdio.h>
int main() {
    float f = 0.0F;
    int i = 0;
    for (f = 0.0;f < 100.0f;f += 0.1f, i++) {
        printf("f: %f\n", f); // 부동소수점을 연산에 사용하면 반올림 혹은 버림 문제 발생
        // 2.799999 부터 출력 문제 발생함 -> 즉 컴퓨터가 실수를 표현하는 방식에는 오차가 존재함.
        // => 부동 소수점 오차 라고 함.
    }
     
    printf("i : %d\n", i);
    return 0;
}