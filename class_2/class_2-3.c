// class_2-3.c : 
// class_2-3.c : �޸� ������ -> ������ ���� �Ǵ� ������ �ڰ��� ������ �����ϴµ� ���
#include <stdio.h>
int main(void) {
	int num1 = 1, num2 = 2;
	printf("Hello, "), printf("world! \n"); // Hello, world! ���
	num1++, num2++; // ���� ���� (���� �� ����) 
	printf("%d ", num1), printf("%d ", num2), printf("\n"); // ���� ������ ���� ���������Ƿ� 2 3 ���
	
	/*
		���Ŀ��� ��ǥ �����ڸ� ����ϸ� �ȵȴ�. (MISRA-C)
			���� :  x = (y=1, y++) -> x=1, y=2
					x = (y=1, z=2) -> y=1, z=2, x=2
	*/
	return 0;
}