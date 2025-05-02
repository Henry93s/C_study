// 문제 25-2. 551p
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;
    char* str, * tmp;

    printf("문자열의 길이는? : ");
    scanf("%d%*c", &n);

    printf("문자열을 입력하시오 : ");
    str = (char*)malloc(sizeof(char) * n);
    fgets(str, n, stdin);

    tmp = (char*)malloc(sizeof(char) * n);
    for (int i = n - 1, cnt = 0; i >= -1; i--) {
        if (str[i] == ' ' || i == -1) {
            for (int j = cnt - 1; j >= 0; j--)
                printf("%c", tmp[j]);
            cnt = 0;
            printf(" ");
        }
        else {
            tmp[cnt++] = str[i];
        }
    }
    printf("\n");

    free(str);
    free(tmp);

    return 0;
}