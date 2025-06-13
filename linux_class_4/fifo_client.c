#include <stdio.h>
#include <fcntl.h>

// system call 을 위함(read, close, unlink())
#include <unistd.h>

#include <sys/stat.h>

#define FIFOFILE	"fifo"

int main(int argc, char** argv){
	int n, fd;
	char buf[BUFSIZ];

	// fifo 를 연다
	if((fd = open(FIFOFILE, O_WRONLY)) < 0){
		perror("open()");
		return -1;
	}

	// 키보드로부터 데이터를 입력받고
	// fifo 로 데이터를 보냄
	while((n = read(0, buf, sizeof(buf))) > 0){
		write(fd, buf, n);
	}

	close(fd);

	return 0;
}
