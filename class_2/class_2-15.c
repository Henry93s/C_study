// class_2-15.c : ���Ĺ��� %o : 8 ����, %x : 16 ����
#include <stdio.h>
int main() {
	int num1 = 7, num2 = 13;
	printf("%o %#o \n", num1, num1); // %o : 8����, %#o : 8���� ǥ�� ���ı�ȣ����
	// -> 7 07
	printf("%x %#x \n", num2, num2); // %x : 16����, %#x : 16���� ǥ�� ���ı�ȣ����
	// -> d oxd

	return 0;
}
