// class_1-4.c : if 조건문
#include <stdio.h>
int main() {
    int num;
    printf("정수 입력: ");
    scanf_s("%d", &num);

    if (num < 0) // num 이 0 보다 작으면 아래의 문장 실행
        printf("입력 값은 0보다 작다.\n"); // 반복문과 마찬가지로 한줄일 때는 중괄호 생략 가능함
    if (num > 0) // num이 0 보다 크면 아래의 문장 실행
        printf("입력 값은 0보다 크다.\n");
    if (num == 0) // num이 0 이면 아래의 문장 실행
        printf("입력 값은 0이다.\n");

    /*
        위 if 문들을 else if, else 로 사용하여 가독성을 높일 수 있음
        if (num < 0){
        ~ } else if (num > 0) { 
        ~ } else {
        ~ }
    */

    return 0;
}