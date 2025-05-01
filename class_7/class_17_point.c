// 파일 입출력 : 파일에 데이터를 쓰고 읽기
#include <stdio.h>
int main() {
	// 파일 입력
	FILE* fp = fopen("data.txt", "wt"); // w : 파일이 없으면 파일을 생성
	// r 이나 r+ 같은 읽기나 읽기 및 쓰기 모드의 경우 파일이 없으면 에러 !
	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	fclose(fp); // 스트림 종료

	// 파일 출력
	// 기존에 파일 스트림이 선언되있으므로 fopen_s 함수를 선언하고 fp 스트림을 지정해
	// fp 파일 스트림 모드 변경.
	fopen_s(fp, "data.txt", "rt");
	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	int ch, i;
	for (i = 0;i < 3;i++) {
		ch = fgetc(fp);
		printf("%c \n", ch);
	}
	fclose(fp); // 스트림 종료

	return 0;
}