// 바이너리 파일 읽고 쓰기(copy 모드)
#include <stdio.h>
int main() {
	FILE* src = fopen("src.bin", "rb"); // b : 바이너리 모드
	FILE* des = fopen("des.bin", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) { // src 나 des 가 없을 때 에러처리
		puts("파일오픈 실패!");
		return -1;
	}
	while (1) {
		readCnt = fread((void*)buf, 1, sizeof(buf), src);
		// 버퍼크기, 레코드크기, 데이터개수, 소스 바이너리 파일 포인터
		if (readCnt < sizeof(buf)) {
			if (feof(src) != 0) {
				fwrite((void*)buf, 1, readCnt, des);
				puts("파일복사 완료!");
				break;
			}
			else {
				puts("파일복사 실패!");
				
			}
			break;
		}
		fwrite((void*)buf, 1, sizeof(buf), des);
	}

	fclose(src);
	fclose(des);

	return 0;
}