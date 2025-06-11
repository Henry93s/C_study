#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Hello, ");
	printf("world!\n");

	// stream 에 있는 버퍼 내용을 프로그램이 강제 종료되기 전에 출력을 한다. 
	// 즉 fflush 는 강제로 버퍼 내용을 출력하는 함수임을 알 수 있다. 
	fflush(stdout);
	_exit(1);
}
