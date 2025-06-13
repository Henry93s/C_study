#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	pid_t pid;
	int pfd[2];
	// <stdio.h> 파일에 정의된 버퍼 크기로 설정
	char line[BUFSIZ];
	int status;

	// pipe() 함수를 이용해서 파이프 생성
	if(pipe(pfd) < 0){
		perror("pipe()");
		return -1;
	}

	// fork() 함수를 이용해서 프로세스 생성
	if((pid = fork()) < 0){
		perror("fork()");
		return -1;
	}else if(pid == 0){ // 자식 프로세스인 경우 처리
		close(pfd[0]); // 읽기를 위한 파일 디스크럽터 닫기
		dup2(pfd[1], 1); // 표준 출력(1)을 쓰기 위한 파일 디스크립터(pfd[1]) 로 변경
		execl("/bin/date", "date", NULL); // date 명령어 수행
		close(pfd[1]); // 쓰기 파일 디스크립터 닫기
		_exit(127);
	}else{ // 부모 프로세스인 경우의 처리
		close(pfd[1]); // 쓰기 파일 디스크립터 닫기
		// 파일 디스크립터로부터 데이터 읽기
		if(read(pfd[0], line, BUFSIZ) < 0){ // 파일 디스크립터로 부터 읽기
			perror("read()");
			return -1;
		}
		printf("%s", line); // 읽은 내용 표시

		close(pfd[0]); // 일기 파일 디스크립터 닫기
		waitpid(pid, &status, 0); // 자식 프로세스 종료를 기다림
	}

	return 0;
}



