// 현재 파일 위치 지시자의 위치 파악 : ftell
#include <stdio.h>
int main() {
	long fpos;
	int i;

	// 파일 생성
	FILE* fp = fopen("text.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);

	// 파일 개방
	fopen_s(fp, "text.txt", "rt");

	for (i = 0;i < 4;i++) {
		putchar(fgetc(fp)); // 1
		fpos = ftell(fp); 
		fseek(fp, -1, SEEK_END); // -
		putchar(fgetc(fp)); 
		fseek(fp, fpos, SEEK_SET);
	fclose(fp);

	return 0;
}