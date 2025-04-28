// class_1-11.c : switch 문 예제
#include <stdio.h>
int main(void)
{
    int score = 0;
    
    // 성적을 입력할 때 0보다 작거나 100보다 클 동안은 계속 score 를 입력받아야함
    do {
        printf("성적을 입력하세요 : ");
        scanf_s("%d", &score);
    } while (score < 0 || score > 100);

    switch (score) { // score 가 95 이상이면 A+ 출력, 90점 이상이면 A 출력
    case 100: case 99: case 98:
    case 97: case 96: case 95: // 여러 case 가 동일한 결과를 나타낼 경우 case 중첩이 가능하나 이런 상황일 경우 if else if 문이 더 좋음
        printf("%d : A+\n", score);
        break;
    case 94: case 93: case 92:
    case 91: case 90:
        printf("%d : A\n", score);
        break;
    
    }
    return 0;
}