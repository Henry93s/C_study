// 446p 문제 3.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int n = 2;
	char name[20], name2[20]; int name_index = 0, name2_index = 0;
	char num[20], num2[20]; int num_index = 0, num2_index = 0;

	char input[100], input2[100];
	fgets(input, sizeof(input), stdin);
	input[strlen(input) - 1] = '\0'; // gets : input 에 있는 개행문자 처리
	fgets(input2, sizeof(input2), stdin);
	input2[strlen(input2) - 1] = '\0'; // gets : input 에 있는 개행문자 처리
	// cf. scanf 의 경우 그냥 변수 받아서 비교 하면 됨.


	// 1. 나의 풀이
	int i, chk;
	chk = 0;
	for (i = 0;input[i] != '\0';i++) {
		if (chk == 0 && input[i] != ' ') {
			name[name_index++] = input[i];
		}
		else if (chk == 0 && input[i] == ' ') {
			chk = 1;
		}
		else {
			num[num_index++] = input[i];
		}
	}

	chk = 0;
	for (i = 0;input2[i] != '\0';i++) {
		if (chk == 0 && input2[i] != ' ') {
			name2[name2_index++] = input2[i];
		}
		else if (chk == 0 && input2[i] == ' ') {
			chk = 1;
		}
		else {
			num2[num2_index++] = input2[i];
		}
	}

	if (strcmp(name, name2) == 1) { // 문자열 비교 시 1, -1, 0 결과 작성 필요!
		printf("이름 같음\n");
	}
	if (strcmp(num, num2) == 1) {
		printf("나이 같음\n");
	}

	// 2. 교재 답안과 다른 점 : atoi(&arr[index1+1]) 을 사용하고, 각각 비교하는 부분을 함수로 구현

	return 0;
}