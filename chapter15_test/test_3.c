// 문제 3. 길이가 10인 배열에서 10개 정수를 입력받고 입력한 숫자가 홀수면 배열의 앞에
// 짝수면 배열의 뒤부터 채워나가는 형식으로 저장하기
#include <stdio.h>
void swap(int* num1, int* num2) {
	
}
int main() {
	int arr[10];
	printf("총 10개의 숫자 입력\n");
	
	int i, temp;
	int oddIndex = 0, evenIndex = 9; // 홀수 일 때는 arr oddIndex 위치에 값을 저장하고 값을 1 씩 증가시킴
	// 짝수일 때는 arr evenIndex 위치에 값을 저장하고 evenIndex 를 1 씩 감소시킴
	for (i = 0;i < 10;i++) {
		printf("입력 : ");
		scanf_s("%d", &temp);

		if (temp % 2 != 0) {
			arr[oddIndex] = temp; 
			oddIndex++; // 홀수일 때는 0 부터 인덱스 1씩 증가
		}
		else {
			arr[evenIndex] = temp;
			evenIndex--; // 짝수일 때는 마지막 인덱스부터 1씩 감소
		}
	}

	for (i = 0;i < 10;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	/* 추가 코드
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