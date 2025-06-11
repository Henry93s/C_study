#include <stdio.h>

int main(int argc, char **argv){
	int n;
	FILE* append, *target;
	char buf[BUFSIZ];

	// 명령행 인수를 복사할 파일명이 없는 경우에 에러를 출력하고 종료한다.
	if(argc != 3){
		fprintf(stderr, "Usage: fcopy file1 file2\n");
		return -1;
	}

	// 원본 파일을 추가 모드로 연다
	if((append = fopen(argv[1], "a")) == NULL){
		perror(argv[1]);
		return -1;
	}

	// 추가시킬 대상 파일을 읽기 모드로 연다
	if((target = fopen(argv[2], "r")) == NULL){
		perror(argv[2]);
		return -1;
	}

	// 추가 파일 내용을 읽어서 원본 파일에 추가한다
	while((n = fread(buf, sizeof(char), BUFSIZ, target)) > 0){
		fwrite(buf, sizeof(char), n, append);
	}

	fclose(target);
	fclose(append);

	return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
	int fd;
	fd = open("samples.txt", O_WRONLY | O_CREAT);
	printf("%d\n", fd); // 파일 디스크럽터 테이블에 따라 2 다음 3 출력 
	close(fd);

	char str[BUFSIZ];
	int n = read(0, str, BUFSIZ);
	printf("Hello, world(%s)\n", str);

	write(1, str, n);
	return 0;
}
