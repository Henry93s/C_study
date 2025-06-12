#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig) //SIGALRM시그널이 발생했을때 호출될 함수
{
        if(sig==SIGALRM) //전달된 인자가 SIGALRM일 경우 아래 문장을 출력
                puts("Time out!");

        alarm(2);  //2초후에 SIGALRM 시그널을 발생시킵니다.
}
void keycontrol(int sig) //SIGINT시그널이 발생했을떄 호출될 함수
{
        if(sig==SIGINT) //전달된 인자가 SIGINT일 경우 아래 문장을 출력
                puts("CTRL+C pressed");
}

int main(int argc, char *argv[])
{
        int i;
        signal(SIGALRM, timeout); //SIGALRM시그널이 발생했을 경우 timeout함수를 실행
        signal(SIGINT, keycontrol); //SIGINT가 발생했을 경우 keycontrol함수를 실행
        alarm(2); //2초 후에 SIGALRM시그널을 발생

        for(i=0; i<3; i++) //3번 반복
        {
                puts("wait..."); //문장 출력
                sleep(100); //100초간 blocking 상태가 됩니다.
        }
        return 0;
}
