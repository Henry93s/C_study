// class_1-10.c : continue 와 break 를 사용한 특정 구구단 출력
#include <stdio.h>
int main() {
	int i, j;
	for (i = 2;i < 10;i++) {
		if (i % 2 != 0) {
			continue; // 2의 배수 단만 출력하기 위하여 i 가 2의 배수가 아닐 때는 continue 처리
		}
		for (j = 1;j < 10;j++) {
			if (j > i) {
				break; // 배수 값 출력은 j 가 i 와 동일할 때의 배수 값만 출력하기 위해서 그 이상의 j 값일 경우 break 로 반복문 탈출
			}
			printf("%d x %d = %d ", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}