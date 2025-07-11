#include <stdio.h>
#include <unistd.h>

// DATA 영역의 초기화된 변수
static int g_var = 1;
char str[] = "PID";

int main(int argc, char** argv){
	// STACK 영역의 지역 변수
	int var;
	pid_t pid;
	var = 92;

	// fork() 함수의 에러 시 처리
	if((pid = fork()) < 0){
		perror("[ERROR] : fork()");
	}else if(pid == 0){ // 자식 프로세스에 대한 처리
		// 변수의 값 변경
		g_var++;
		var++;
		printf("Parent %s from Child Process(%d) : %d\n",
				str, getpid(), getppid());
	}else{ // 부모 프로세스에 대한 처리
		printf("Child %s from Parent Process(%d) : %d\n",
				str, getpid(), pid);
		sleep(1);
	}

	// 변수 내용 출력
	printf("pid = %d, Global var = %d, var = %d\n",
			getpid(), g_var, var);

	return 0;
}
