#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
int main(int argc, char** argv){
	int i,j;
	time_t rawtime;
	struct tm* tm;
	char buf[BUFSIZ];
	struct timeval mytime;

	// 현재 시간 구하기
	time(&rawtime);
	// 현재 시간을 화면에 출력
	printf("time : %u\n", (unsigned)rawtime);

	// 현재 시간 구하기
	gettimeofday(&mytime, NULL);
	printf("gettimeofday : %ld/%d\n", mytime.tv_sec, mytime.tv_usec);

	// 현재 시간을 문자열로 바꿔서 출력
	printf("ctime: %s", ctime(&rawtime));

	// 환경 변수 설정
	putenv("TZ=PST3PDT"); // 미국 대서양 어딘가
	// TZ 변수 설정
	tzset();
	// tm = gmtime(&rawtime);
	tm = localtime(&rawtime);
	// 현재 시간을 tm 구조체를 이용해 출력
	printf("asctime : %s", asctime(tm));

	// 사용자 정의 문자열 지정
	strftime(buf, sizeof(buf), "%a %b %e %H:%M:%S %Y", tm);
	printf("strftime : %s\n", buf);

	return 0;
}

