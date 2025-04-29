#include <stdio.h>
int main(void)
{
    int arr[4][4], rot[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", (j + 1) + i * 4);
        }
        printf("\n");
    }

    printf("************\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[j][4 - 1 - i] = j + 1 + i * 4;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("************\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            rot[j][4 - 1 - i] = arr[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", rot[i][j]);
        }
        printf("\n");
    }

    printf("************\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[j][4 - 1 - i] = rot[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}