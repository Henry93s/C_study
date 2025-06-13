#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>

extern char** environ;

int system(char* cmd){
	pid_t pid;
	int status;
	char* argv[] = {"sh", "-c", cmd, NULL};

	posix_spawn(&pid, "/bin/sh", NULL, NULL, argv, environ);

	waitpid(pid, &status, 0);

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

