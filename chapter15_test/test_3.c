// ���� 3. ���̰� 10�� �迭���� 10�� ������ �Է¹ް� �Է��� ���ڰ� Ȧ���� �迭�� �տ�
// ¦���� �迭�� �ں��� ä�������� �������� �����ϱ�
#include <stdio.h>
void swap(int* num1, int* num2) {
	
}
int main() {
	int arr[10];
	printf("�� 10���� ���� �Է�\n");
	
	int i, temp;
	int oddIndex = 0, evenIndex = 9; // Ȧ�� �� ���� arr oddIndex ��ġ�� ���� �����ϰ� ���� 1 �� ������Ŵ
	// ¦���� ���� arr evenIndex ��ġ�� ���� �����ϰ� evenIndex �� 1 �� ���ҽ�Ŵ
	for (i = 0;i < 10;i++) {
		printf("�Է� : ");
		scanf_s("%d", &temp);

		if (temp % 2 != 0) {
			arr[oddIndex] = temp; 
			oddIndex++; // Ȧ���� ���� 0 ���� �ε��� 1�� ����
		}
		else {
			arr[evenIndex] = temp;
			evenIndex--; // ¦���� ���� ������ �ε������� 1�� ����
		}
	}

	for (i = 0;i < 10;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	/* �߰� �ڵ�
		#include <stdio.h>
		int main(void)
		{
		  int num[10], a;
		  int *start = num;
		  int *end = num+9;
		  for(int i = 0; i < 10; i++) {
			printf("%d : ", i+1), scanf("%d", &a);
			if((a&01)==0)*(end--)=a; else *(start++)=a;
		  }
		  printf("Print the Element of Array : [");
		  for(int i = 0; i < 10; i++) {
			printf("%d, ", num[i]);
		  }
		  printf("\b\b]\n");

		  return 0;
		}
	*/
	
	return 0;
}