// class_1-7.c : 삼항 연산자 조건을 활용하여 절댓값 구하기
#include <stdio.h>
int main() {
    int num, abs;
    printf("정수 입력: ");
    scanf_s("%d", &num);

    abs = num > 0 ? num : num * (-1); // 입력한 정수가 음수일 때만 -1 를 곱하여 절댓값을 구함
    printf("절댓값: %d \n", abs);
    return 0;
}