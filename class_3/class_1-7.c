// class_1-7.c : ���� ������ ������ Ȱ���Ͽ� ���� ���ϱ�
#include <stdio.h>
int main() {
    int num, abs;
    printf("���� �Է�: ");
    scanf_s("%d", &num);

    abs = num > 0 ? num : num * (-1); // �Է��� ������ ������ ���� -1 �� ���Ͽ� ������ ����
    printf("����: %d \n", abs);
    return 0;
}