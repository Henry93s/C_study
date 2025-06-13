#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>

#define MSGKEY	51234 // 임의로 설정한 키 값

struct msgbuf{
	long mtype; // 메시지 타입 : 0 이상의 정수값
	char mtext[BUFSIZ]; // 메시지 내용 : 1바이트 이상
};

int main(int argc, char** argv){
	key_t key;
	int n, msqid;
	struct msgbuf mb;

	key = MSGKEY;
	// 메시지 큐 채널 생성
	if((msqid = msgget(key, IPC_CREAT | IPC_EXCL | 0666)) < 0) {
		perror("msgget()");
		return -1;
	}

	// 메시지 큐에서 데이터를 가져옴
	while((n = msgrcv(msqid, &mb, sizeof(mb), 0,0)) > 0){
		switch(mb.mtype){
			// 메시지 타입이 1이면 가져온 데이터를 화면에 출력
			case 1:
				write(1, mb.mtext, n);
				break;
			case 2:
				// 메시지 타입이 2면 메시지 큐 채널 삭제
				if(msgctl(msqid, IPC_RMID, (struct msqid_ds*) 0) < 0){
					perror("msgctl()");
					return -1;
				}
				break;
		}
	}

	return 0;
}
