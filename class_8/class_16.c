// ���ڿ� ������ ��ũ�� �Ű����� ġȯ�ǵ��� ����� : # ������
#include <stdio.h>
#define STRING_JOB(A,B) #A "�� ������ " #B "�Դϴ�."
// => ���ڿ������� "ABC " " DEF �� "ABC  DEF" �� ����. 

int main() {
	printf("%s \n", STRING_JOB(�̵���, ������));
	printf("%s \n", STRING_JOB(�ѻ��, ��ɲ�));
	
	return 0;
}