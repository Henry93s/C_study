// class_13.c: 388p ���� 5. ������ ����(����)
#include <stdio.h>
int main() {
	int arr[2][2][2] = { 1,2,3,4,5,6,7,8 };
	printf("%d \n", arr[1][0][1]);
	// �� print �� ���� ���� 5�� �̻�
	printf("%d \n", *(*(*(arr + 1)) + 1));
	printf("%d \n", *((*(arr[1])) + 1) );
	printf("%d \n", (**(arr + 1))[1]);
	printf("%d \n", (**arr[1] + 1));
	printf("%d \n", *(*arr[1] + 1));
	//printf("%d \n", )
	/* ���
		#include <stdio.h>

		int main(void) 
		{
		  int arr[2][2][2] = {1, 2, 3, 4, 5, 6, 7, 8};
		  printf("%d\n", arr[1][0][1]);
		  printf("%d\n", (*(arr+1))[0][1]);     // 1  
		  printf("%d\n", (*(arr[1]+0))[1]);     // 2
		  printf("%d\n", (*(*(arr+1)+0))[1]);   // 3
		  printf("%d\n", *(*(*(arr+1)+0)+1));   // 4
		  printf("%d\n", (**(arr+1+0))[1]);     // 5
		  printf("%d\n", *(arr[1][0]+0+1)); // 6
		  printf("%d\n", *(&arr[0][0][0]+1+0*2+1*4)); // 7
		  return 0;
		}
	*/
}