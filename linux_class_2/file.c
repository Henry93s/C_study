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
