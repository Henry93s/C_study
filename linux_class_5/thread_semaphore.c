#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

// 세마포어를 위한 전역변수
sem_t* sem;
// 임계 구역 변수
int g_var = 1;

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
	// critical section lock
	v();
	printf("Inc : %d < Before\n", g_var);
	g_var++;
	printf("Inc : %d > After\n", g_var);
	// critical section unlock
	p();
	return NULL;
}

// P 연산을 수행하기 위한 함수
void *pthreadP(void* arg){
	// critical section lock
	v();
	printf("Dec : %d < Before\n", g_var);
	g_var--;
	printf("Dec : %d > After\n", g_var);
	// critical section unlock
	p();
	return NULL;
}

int main(int argc, char** argv){
	// 스레드를 위한 자료형
	pthread_t ptV, ptP;

	const char* name = "thread_sem";
    // 세마포어 값
	// 초기 세마포어 값을 1로 설정해서 단 하나의 스레드만 자원에 접근할 수 있도록 함
	// 하나의 스레드가 접근했을 때 0 이 되어서 다른 스레드는 접근할 수 없는 상태가 되고
	// 이후 sem_post() == p() 함수가 동작하면 다시 1이 되어 다른 스레드가 접근할 수 있음
    unsigned int value = 1;

    // 세마포어 열기
    sem = sem_open(name, O_CREAT, S_IRUSR | S_IWUSR, value);

	// 스레드 생성
	pthread_create(&ptV, NULL, pthreadV, NULL);
	pthread_create(&ptP, NULL, pthreadP, NULL);
	
	// 스레드가 종료될 때까지 대기
	pthread_join(ptP, NULL);
	pthread_join(ptV, NULL);

	// 다쓴 세마포어 닫고 정리
    sem_close(sem);
    printf("sem_destroy(): %d\n", sem_destroy(sem));

    // 세마포어 삭제
    sem_unlink(name);

	return 0;
}
