// ���Ǻ� �������� ���� ��ũ�� : #if ... #endif
#include <stdio.h>
#define ADD 1
#define MIN 0

int main() {
	int num1, num2;
	printf("�� ���� ���� �Է�; ");
	scanf_s("%d %d", &num1, &num2);

#if ADD // ADD �� ���� �� (���Ǻ� �������� ��� ���ǿ� ���� #if ~ #endif ���� ������ �������Ѵ�.
	printf("%d + %d = %d\n", num1, num2, num1 + num2); // ����
#endif

#if MIN // MIN �� ���� �� -> 0
	printf("%d - %d = %d\n", num1, num2, num1 - num2); // �������� ����!!!
#endif

	return 0;
}