// class_1-17.c : ���������� ����
#include <stdio.h>
void Add(int val); // parameter val �� �������� num �� ���ϴ� �Լ�
int num; // ���������� ���α׷��� ���� ������ �޸𸮿� �����ϴ� ����
// �⺻�����δ� 0 ���� �ʱ�ȭ��. (���������� ��� �⺻������ �����Ⱚ �ʱ�ȭ)
int main() {
	printf("num: %d\n", num); // 0 ��� <- �⺻������ 0 ���� �ʱ�ȭ�Ǳ� ������
	Add(3); // num => 3;
	printf("num: %d\n", num); // 3
	num++;	// num => 4
	printf("num: %d\n", num); // 4
	return 0;
}
void Add(int val) {
	num += val;
}