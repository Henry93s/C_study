#include <stdio.h>
#include <string.h>

int main(void) {
	FILE* fp = fopen("text.txt", "rt"); // 파일 포인터 선언 및 읽기 모드 초기화
	int ret;
	char text;
	int aCnt = 0, pCnt = 0; // A 로 시작하는 문자 또는 P 로 시작하는 문자 카운트 변수 초기화
	int isFirst = 1; // 문자열의 첫 글자임을 알리는 flag

	while (1) {
		ret = fgetc(fp); // fgetc 로 int ret 에 받고 EOF 일 때 반복문 탈출
		// 공백(\n 포함) 문자는 text 에 담지 않고 공백 문자를 기준으로 문자열을 구분
		// <-> fgets 나 fgetc 의 경우 공백 문자도 문자열로 받아서 공백 처리가 추가로 필요함 !
		if (ret == EOF) {
			break;
		}
		if (isFirst && ret == 'A') { // 문자열 첫글자가 A 일 때 acnt++
			aCnt++;
			isFirst = 0;
		}
		else if (isFirst && ret == 'P') { // 첫글자가 P 일 때 bcnt++
			pCnt++;
			isFirst = 0;
		}

		if (ret == ' ' || ret == '\n' || ret == '\t') { 
			// fgetc 에서 공백 문자들이 올 경우 다음 받을 문자는
			// 문자열의 첫 글자로 처리하도록 하는 컨트롤 변수 처리
			isFirst = 1;
		}
		printf("%c\n", ret); // 확인용 문자열 출력
	}

	printf("A로 시작하는 단어의 수: %d\n", aCnt);
	printf("P로 시작하는 단어의 수: %d\n", pCnt);

	fclose(fp);

	return 0;
}