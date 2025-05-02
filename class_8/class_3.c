// 파일 위치 지시자의 이동 : fseek
// 성공시 0, 실패시 0 이 아닌 값을 반환
#include <stdio.h>
int main() {
	// 파일 생성
	FILE* fp = fopen("text.txt", "wt");
	fputs("123456789", fp);
	fclose(fp);

	// 파일 개방
	fopen_s(fp, "text.txt", "rt");

	// seek_end test
	fseek(fp, -2, SEEK_END); // EOF 에서 왼쪽으로 2칸 이동
	putchar(fgetc(fp)); // 8

	// seek_set test
	fseek(fp, 2, SEEK_SET); // 첫 번째 위치에서 오른쪽으로 2칸 이동
	putchar(fgetc(fp)); // 3 // 이 출력되면서 자동으로 파일 포인터는 4 를 가리킨다.

	// seek_cur test
	fseek(fp, 2, SEEK_CUR); // 현재 위치(4) 에서 오른쪽으로 2칸 이동
	putchar(fgetc(fp)); // 6

	fclose(fp);
	return 0;
}