// class_1-13.c : function Ȱ�� 2
#include <stdio.h>
int Add(int num1, int num2) { // ���� �Լ�
	return num1 + num2;
}
void ShowAddResult(int num) { // ���� ��� ��� �Լ�
	printf("������� ���: %d \n", num);
}
int ReadNum(void) { // ���� ��� �� read �Լ�
	int num;
	scanf_s("%d", &num);
	return num;
}
void HowToUseThisProg(void) { // ���� ���α׷� ���̵� ��� �Լ�
	printf("�� ���� ������ �Է��Ͻø� ��������� ��µ˴ϴ�. \n");
	printf("��! �׷� �� ���� ������ �Է��ϼ���. \n");
}

int main() {
	int result, num1, num2;
	HowToUseThisProg();
	num1 = ReadNum();
	num2 = ReadNum();
	result = Add(num1, num2); 
	ShowAddResult(result);

	return 0;
}