// class_2-14.c : 
// ����� �� ��ȯ : ���� �� ��ȯ
#include <stdio.h>
int main(void) {
	int num1 = 3, num2 = 4;
	double divResult;
	divResult = num1 / num2;
	printf("������ ���: %f \n", divResult); // 0.000000 <- ������ ������ ��� ���̹Ƿ� 0 �̰� �̸� %f �� ��� �����Ƿ�
	divResult = (double)num1 / num2;
	printf("������ ���: %f \n", divResult); // 0.750000 <- num1 �� ����� �� ��ȯ�ϰ�, �� num2 �� ������ �� ��ȯ �ȴ�. (3.0 / 4.0)

	return 0;
}
