#include <stdio.h>
#include <string.h>
int main(void) {
	FILE* fp1 = fopen("d1.txt", "rt");
	FILE* fp2 = fopen("d2.txt", "rt");

	char text1, text2; // 파일을 임시로 담기 위한 문자 변수 선언
	int same = 1; // 두 개의 파일이 같은지 다른지 구분하기 위한 변수 초기화

	while (1) {
		text1 = fgetc(fp1); // 공백 문자를 포함해서 한 글자씩 문자를 받음.
		text2 = fgetc(fp2);
		if (text1 == EOF && text2 != EOF) { // 파일 둘 중에 하나만 EOF 일 경우 이미 길이에서 부터 차이가 있으므로
			// same 을 false 로 지정하고 break;
			same = 0;
			break;
		}
		else if (text2 == EOF && text1 != EOF) {
			same = 0;
			break;
		}

		if (text1 != text2) {
			same = 0;
			break; // 파일 내 공백 포함 하나라도 문자가 다를 경우 이미 다른 파일이므로 break 처리 후 탈출
		}
		if (text1 == EOF && text2 == EOF) {
			break; // 파일 내 문자 길이는 일치함.
		}
	}

	if (same == 1) {
		printf("두 개의 파일은 완전히 일치합니다.\n");
	}
	else {
		printf("두 개의 파일은 일치하지 않습니다.\n");
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}