#include <stdio.h>
#include <signal.h> // signal() 함수를 위해 사용
#include <stdlib.h> // exit 함수를 위해 사용
#include <string.h> // strsignal 함수를 위해 사용
#include <unistd.h>

static void printSigset(sigset_t* set); // 현재 sigset_t 에 설정된 시그널 표시
static void sigHandler(int); // 시그널 처리용 핸들러

int main(int argc, char** argv){
	// 블록할 시그널을 등록할 sigset_t 형
	sigset_t pset;
	// 모두 0 설정
	sigemptyset(&pset);
	// SIGQUIT 와 SIGRTMIN 을 설정
	sigaddset(&pset, SIGQUIT);
	sigaddset(&pset, SIGRTMIN);
	// 현재 시그널 마스크에 추가
	sigprocmask(SIG_BLOCK, &pset, NULL);

	// 현재 설정된 sigset_t 를 화면으로 출력
	printSigset(&pset);

	// SIGINT 의 처리를 위한 핸들러 등록
	if(signal(SIGINT, sigHandler) == SIG_ERR){
		perror("signal() : SIGINT");
		return -1;
	}

	// SIGUSR1 처리를 위한 핸들러 등록
	if(signal(SIGUSR1, sigHandler) == SIG_ERR){
		perror("signal() : SIGUSR1");
		return -1;
	}

	// SIGUSR2 처리를 위한 핸들러 등록
	if(signal(SIGUSR2, sigHandler) == SIG_ERR){
		perror("signal() : SIGUSR2");
		return -1;
	}
	
	// SIGPIPE 처리를 위한 핸들러 등록
	if(signal(SIGPIPE, SIG_IGN) == SIG_ERR){
		perror("signal() : SIGPIPE");
		return -1;
	}

	// 시그널 처리를 위한 대기
	while(1){
		pause();
	}

	return 0;
}

// 시그널 번호를 인자로 받음
static void sigHandler(int signo){
	// SIGINT 시그널이 발생했을 때 처리
	if(signo == SIGINT){
		printf("SIGINT is catched : %d\n", signo);
		exit(0);
	}else if(signo == SIGUSR1){
		// SIGUSR1 이 발생했을 때 처리
		printf("SIGUSR1 is catched\n");	
	}else if(signo == SIGUSR2){
		// SIGUSR2 이 발생했을 때 처리
		printf("SIGUSR2 is catched\n");
	}else if(signo == SIGQUIT){
		printf("SIGQUIT is catched\n");
		sigset_t uset;
		sigemptyset(&uset);
		sigaddset(&uset, SIGINT);
		sigprocmask(SIG_UNBLOCK, &uset, NULL);
	}else{
		fprintf(stderr, "Catched signal : %s\n", strsignal(signo));
	}
}

static void printSigset(sigset_t* set){
	int i;
	// sigset_t 에 설정된 전체 비트를 출력
	for(i = 0; i< NSIG; ++i){
		printf((sigismember(set, i)) ? "1" : "0");
	}
	putchar('\n');
}
	
