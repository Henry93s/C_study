// 문자열 단위로 읽고 쓰기
#include <stdio.h>
int main() {
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("des.txt", "wt");
	char str[20];

	if (src == NULL || des == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	while (fgets(str, sizeof(str), src) != NULL) { // fget's' 이므로 문자열 단위
		// 로 파일을 읽고 NULL 끝나기 전까지 des 파일에 puts 문자열을 출력한다.
		fputs(str, des);
	}

	if (feof(src) != 0) { // feof 가 0 이 아닌 값 반환 : 정상동작 완료
		puts("파일복사 완료!");
	}
	else {
		puts("파일복사 실패!");
	}

	fclose(src);
	fclose(des);

	return 0;
}