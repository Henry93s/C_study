// class_1-9.c : continue ���� ������ ��� ���� ������ �����ϰ� �ݺ������� Ȯ���ϴ� �������� �̵��Ѵ�.
#include <stdio.h>
int main() {
    int num;
    printf("start! ");

    for (num = 1;num < 20;num++) {
        if (num % 2 == 0 || num % 3 == 0) {
            continue; // num �� 2�� ����̰ų� 3�� ����� ��� ���� print ���� ������� �ʰ� �ݺ������� Ȯ���ϴ� �������� �̵���.
        }
        printf("%d ", num);
    }
    printf("end! \n");
    return 0;
}