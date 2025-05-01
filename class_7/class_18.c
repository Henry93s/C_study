// feof : 파일의 끝에 도달한 경우 0 이 아닌 값 반환
// feof 를 이용하여 파일을 읽고 복사하기
#include <stdio.h>
int main() {
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("dst.txt", "wt");
	int ch;

	if (src == NULL || des == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	do { // src 소스 파일에서 파일 데이터 끝까지 도달하지 않을 때까지
		ch = fgetc(src); 
		fputc(ch, des); // des 목적 파일에 ch 값 을 출력
	} while (ch != EOF);

	if (feof(src) != 0) { // feof 0 이 아닌 값 반환 -> 파일 복사 완료
		puts("파일복사 완료!");
	}
	else {
		puts("파일복사 실패!");
	}

	fclose(src);
	fclose(des);

	return 0;
}