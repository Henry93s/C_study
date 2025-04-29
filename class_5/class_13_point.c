// class_13.c: 388p 문제 5. 포인터 이해(최종)
#include <stdio.h>
int main() {
	int arr[2][2][2] = { 1,2,3,4,5,6,7,8 };
	printf("%d \n", arr[1][0][1]);
	// 위 print 와 같은 문장 5개 이상
	printf("%d \n", *(*(*(arr + 1)) + 1));
	printf("%d \n", *((*(arr[1])) + 1) );
	printf("%d \n", (**(arr + 1))[1]);
	printf("%d \n", (**arr[1] + 1));
	printf("%d \n", *(*arr[1] + 1));
	//printf("%d \n", )
	/* 답안
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