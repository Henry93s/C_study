#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sys/socket.h>

int main(int argc, char** argv){
	// 2개의 int 형 소켓 디스크립터 배열 생성
	int ret, sock_fd[2];
	int status;
	char buf[] = "Hello world", line[BUFSIZ];
	pid_t pid;

	// 한 쌍의 소켓을 생성
	// socketpair 는 로컬 도메인만 사용 -> AF_LOCAL
	// , 스트림 통신을 위한 SOCK_STREAM
	ret = socketpair(AF_LOCAL, SOCK_STREAM, 0, sock_fd);
	if(ret == -1){
		perror("socketpair()");
		return -1;
	}

	// 각 소켓의 디스크립트 번호 출력
	printf("socket 1: %d\n", sock_fd[0]);
	printf("socket 2: %d\n", sock_fd[1]);

	if((pid=fork()) < 0){
		perror("fork()");
	}else if(pid == 0){
		// 자식 프로세스일 때의 처리
		// 부모 프로세스로 데이터를 보낸다.
		// 소켓을 열고 데이터를 주고받을 때 파일 입출력 기본 함수 write, read 사용
		write(sock_fd[0], buf, strlen(buf) + 1);
		printf("Data send : %s\n", buf);

		// 소켓 닫기
		close(sock_fd[0]);
	} else {
		// 부모 프로세스일 때 처리
		// 자식 프로세스의 종료를 대기한다.
		wait(&status);

		// 자식 프로세스에서 온 데이터를 읽는다.
		read(sock_fd[1], line, BUFSIZ);
		printf("Received data : %s\n", line);

		// 소켓 닫기
		close(sock_fd[1]);
	}

	return 0;
}
