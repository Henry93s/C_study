// 공용체의 접근 방식
// 하나의 메모리 공간을 둘 이상의 방식으로 접근할 때 사용
#include <stdio.h>
typedef struct dbshort {
	unsigned short upper; // 2 byte
	unsigned short lower; // 2 byte
} DBShort;

typedef union rdbuf {
	int iBuf; // 4 byte
	char bBuf[4]; // 4
	DBShort sBuf; // 4
} RDBuf;

int main() {
	RDBuf buf; // 4 byte 할당
	printf("정수 입력: ");
	scanf_s("%d", &(buf.iBuf)); // input : 1145258561

	printf("상위 2바이트: %u\n", buf.sBuf.upper); // 16961
	printf("하위 2바이트: %u\n", buf.sBuf.lower); // 17475
	printf("상위 1바이트 아스키 코드: %c \n", buf.bBuf[0]); // A
	printf("하위 1바이트 아스키 코드: %c \n", buf.bBuf[3]); // D

	return 0;
}