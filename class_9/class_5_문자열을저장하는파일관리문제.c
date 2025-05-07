#include <stdio.h>
#include <string.h>

int main(void) {
	FILE* fp = fopen("text.txt", "rt"); // 파일 포인터 선언 및 읽기 모드 초기화
	int ret;
	char text[50]; // 문자열을 담기위한 text 배열
	int aCnt = 0, pCnt = 0; // A 로 시작하는 문자 또는 P 로 시작하는 문자 카운트 변수 초기화
	while (1) {
		ret = fscanf_s(fp, "%s", text, 50); // fscanf 로 int ret 에 받고 EOF 일 때 반복문 탈출
		// 공백(\n 포함) 문자는 text 에 담지 않고 공백 문자를 기준으로 문자열을 구분
		// <-> fgets 의 경우 공백 문자도 문자열로 받아서 공백 처리가 추가로 필요함 !
		if (ret == EOF) {
			break;
		}
		if (text[0] == 'A') { // 문자열 첫글자가 A 일 때 acnt++
			aCnt++;
		}
		else if (text[0] == 'P') { // 첫글자가 P 일 때 bcnt++
			pCnt++;
		}
		printf("%s\n", text); // 확인용 문자열 출력
	}

	printf("A로 시작하는 단어의 수: %d\n", aCnt);
	printf("P로 시작하는 단어의 수: %d\n", pCnt);

	fclose(fp);

	return 0;
}