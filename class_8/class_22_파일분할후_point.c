#include <stdio.h>
extern int num; // num �� �ܺ� ���Ͽ��� ����� �������� ǥ��
// !!! �������������� static :  �ܺ� ���Ͽ��� int num = 0; �� �ƴ�
// static int num = 0; ���� �������� ������ �ٸ� ���Ͽ��� �ش� ������ ������ �� ���� !!
extern void Increment(); // Increment �Լ��� extern �������� �ܺο� �ִ� �Լ����� ǥ��
extern int GetNum();
// �Լ��� �ܺο��� static void Increment() ó�� �ܺ� ���Ͽ��� �������� ��
// ���������� ������ �� ����.

int main(void) {
	printf("num: %d\n", GetNum());
	Increment();
	printf("num: %d\n", GetNum());
	Increment();
	printf("num: %d\n", GetNum());

	return 0;
}