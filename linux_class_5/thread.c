#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

// 세마포어를 위한 전역변수
sem_t* sem;
// 임계 구역 변수
static int cnt = 0;

// P 연산
void p(){
	sem_post(sem);
}

// V 연산
void v(){
	sem_wait(sem);
}

// v 연산을 수행하기 위한 함수
void *pthreadV(void* arg){
	int i;
	for(i=0;i<10;i++){
		// 7이상이면 100 millisec 대기
		if(cnt >= 7){
			usleep(100);
		}
		v();
		cnt++;
		printf("increase: %d\n", cnt);
		fflush(NULL);
	}

	return NULL;
}

// P 연산을 수행하기 위한 함수
void *pthreadP(void* arg){
	int i;
	for(i=0;i<10;i++){
		// 세마포어가 0이되면 블록처리
		p();
		cnt--;
		printf("decrease: %d\n", cnt);
		fflush(NULL);
		// 100 millisec 대기
		usleep(100);
	}

	return NULL;
}

int main(int argc, char** argv){
	// 스레드를 위한 자료형
	pthread_t ptV, ptP;

	const char* name = "posix_sem";
	// 세마포어 값
	unsigned int value = 7;

	// 세마포어 열기
	sem = sem_open(name, O_CREAT, S_IRUSR | S_IWUSR, value);

	// 스레드 생성
	pthread_create(&ptV, NULL, pthreadV, NULL);
	pthread_create(&ptP, NULL, pthreadP, NULL);
	// 스레드가 종료될 때까지 대기
	pthread_join(ptV, NULL);
	pthread_join(ptP, NULL);

	// 다쓴 세마포어 닫고 정리
	sem_close(sem);
	printf("sem_destroy(): %d\n", sem_destroy(sem));

	// 세마포어 삭제
	sem_unlink(name);

	return 0;
}
