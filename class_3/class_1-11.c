// class_1-11.c : switch �� ����
#include <stdio.h>
int main(void)
{
    int score = 0;
    
    // ������ �Է��� �� 0���� �۰ų� 100���� Ŭ ������ ��� score �� �Է¹޾ƾ���
    do {
        printf("������ �Է��ϼ��� : ");
        scanf_s("%d", &score);
    } while (score < 0 || score > 100);

    switch (score) { // score �� 95 �̻��̸� A+ ���, 90�� �̻��̸� A ���
    case 100: case 99: case 98:
    case 97: case 96: case 95: // ���� case �� ������ ����� ��Ÿ�� ��� case ��ø�� �����ϳ� �̷� ��Ȳ�� ��� if else if ���� �� ����
        printf("%d : A+\n", score);
        break;
    case 94: case 93: case 92:
    case 91: case 90:
        printf("%d : A\n", score);
        break;
    
    }
    return 0;
}