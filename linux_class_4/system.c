#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

// fork(), exec(), waitpid() 함수를 사용
int system(const char* cmd){
	pid_t pid;
	int status;

	if((pid = fork()) < 0){
		status = -1;
	}else if(pid == 0){ // 자식 프로세스 처리
		execl("/bin/sh", "sh", "-c", cmd, (char*)0);
		// excel 함수 에러 사항
		_exit(127);
	}else{ // 부모 프로세스 처리
		// 자식 프로세스의 종료 대기
		while(waitpid(pid, &status, 0) < 0){
			// waitpid() 함수에서 EINTR 이 아닌 경우
			if(errno != EINTR){
				status = -1;
				break;
			}
		}
	}

	return status;
}

int main(int argc, char** argv, char** envp){
	// 환경 변수 출력
	while(*envp){
		printf("%s\n", *envp++);
	}

	// who 유틸리티 수행
	system("who");
	// 오류 사항 수행
	system("nocommand");
	// cal 유틸리티 수행
	system("cal");

	return 0;
}

