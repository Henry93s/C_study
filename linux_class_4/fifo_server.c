#include <stdio.h>
#include <fcntl.h>

// system call 을 위함(read, close, unlink())
#include <unistd.h>

#include <sys/stat.h>

#define FIFOFILE	"fifo"

int main(int argc, char** argv){
	int n, fd;
	char buf[BUFSIZ];

	// 기본 fifo 파일 삭제
	unlink(FIFOFILE);

	// 새fifo 파일 생성
	if(mkfifo(FIFOFILE, 0666) < 0){
		perror("mkfifo()");
		return -1;
	}

	// fifo 를 연다
	if((fd = open(FIFOFILE, O_RDONLY)) < 0){
		perror("open()");
		return -1;
	}

	// fifo 로부터 데이터를 받아옴
	while((n = read(fd, buf, sizeof(buf))) > 0){
		printf("%s", buf);
	}

	close(fd);

	return 0;
}
