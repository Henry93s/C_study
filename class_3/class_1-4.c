// class_1-4.c : if ���ǹ�
#include <stdio.h>
int main() {
    int num;
    printf("���� �Է�: ");
    scanf_s("%d", &num);

    if (num < 0) // num �� 0 ���� ������ �Ʒ��� ���� ����
        printf("�Է� ���� 0���� �۴�.\n"); // �ݺ����� ���������� ������ ���� �߰�ȣ ���� ������
    if (num > 0) // num�� 0 ���� ũ�� �Ʒ��� ���� ����
        printf("�Է� ���� 0���� ũ��.\n");
    if (num == 0) // num�� 0 �̸� �Ʒ��� ���� ����
        printf("�Է� ���� 0�̴�.\n");

    /*
        �� if ������ else if, else �� ����Ͽ� �������� ���� �� ����
        if (num < 0){
        ~ } else if (num > 0) { 
        ~ } else {
        ~ }
    */

    return 0;
}