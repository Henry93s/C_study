#include <stdio.h>
#include <pthread.h>

int g_var = 1;
pthread_mutex_t mid;

void* inc_function(void*);
void* dec_function(void*);

int main(int argc, char** argv){
	pthread_t ptInc, ptDec;

	// 뮤텍스 초기화
	pthread_mutex_init(&mid, NULL);

	pthread_create(&ptInc, NULL, inc_function, NULL);
	pthread_create(&ptDec, NULL, dec_function, NULL);

	pthread_join(ptInc, NULL);
	pthread_join(ptDec, NULL);

	// 뮤텍스 삭제
	pthread_mutex_destroy(&mid);

	return 0;
}

void* inc_function(void* arg){
	// critical section lock
	pthread_mutex_lock(&mid);
	printf("Inc : %d < before\n", g_var);
	g_var++;
	printf("Inc : %d > after\n", g_var);
	pthread_mutex_unlock(&mid);
	return NULL;
}


void* dec_function(void* arg){
	// critical section lock
	pthread_mutex_lock(&mid);
	printf("Dec : %d < before\n", g_var);
	g_var--;
	printf("Dec : %d > after\n", g_var);
	pthread_mutex_unlock(&mid);
	return NULL;
}
