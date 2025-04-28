// class_1-9.c : continue 문이 동작할 경우 이후 동작은 생략하고 반복조건을 확인하는 과정으로 이동한다.
#include <stdio.h>
int main() {
    int num;
    printf("start! ");

    for (num = 1;num < 20;num++) {
        if (num % 2 == 0 || num % 3 == 0) {
            continue; // num 이 2의 배수이거나 3의 배수일 경우 이후 print 문은 출력하지 않고 반복조건을 확인하는 과정으로 이동함.
        }
        printf("%d ", num);
    }
    printf("end! \n");
    return 0;
}