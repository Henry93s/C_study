#include <stdio.h>
#include <math.h>
int main(void) {
    int n;

    printf("%d\n\n\n\n", 'Z' - 'L');
    scanf_s("%d", &n);

    int i, j;

    char ascii_start = 65;
    char ascii_rowsum = abs(65 + (n * n - 1));

    // test ÇÊ¿ä
    while (abs(ascii_rowsum) > 90) {
        for (i = 1;i <= abs(ascii_rowsum) - 90;i++) {
            ascii_start++;
        }
        ascii_rowsum = abs(ascii_start);
    }

    char ascii_sum;

    for (i = 1;i <= n; i++) {
        if (i != 1) {
            ascii_rowsum -= 1;
        }
        ascii_sum = ascii_rowsum;
        for (j = 1;j <= n; j++) {
            printf("%c ", ascii_sum);
            ascii_sum -= 4;
        }
        printf("\n");
    }

    return 0;
}