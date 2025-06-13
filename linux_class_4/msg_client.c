#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/msg.h>

#define MSGKEY	51234

struct msgbuf{
	long mtype; // 메시지 타입 : 0 이상의 정수값
	char mtext[BUFSIZ]; // 메시지 내용 : 1바이트 이상
};

int main(int argc, char** argv){
	key_t key;
	int rc, msqid;
	char* msg_text = "hello world!\n";
	struct msgbuf* mb;
	mb = (struct msgbuf*)malloc(sizeof(struct msgbuf)+strlen(msg_text));

	key = MSGKEY;

	// 메시지 큐 채널을 가져옴
	if((msqid = msgget(key, 0666)) < 0) {
		perror("msgget()");
		return -1;
	}

	// mtype 을 1로 설정하고 hello world 라는 문자열을 보냄
	mb->mtype = 1;
	strcpy(mb->mtext, msg_text);
	// 메시지 큐로 데이터를 보냄
	rc = msgsnd(msqid, mb, strlen(msg_text) + 1, 0);
	if(rc == -1){
		perror("msgsnd()");
		return -1;
	}

	// mtype 을 2로 설정하고 보냄
	mb->mtype = 2;
	memset(mb->mtext, 0, sizeof(mb->mtext));
	if(msgsnd(msqid, mb, sizeof(mb->mtext), 0) < 0){
		perror("msgsnd()");
		return -1;
	}

	return 0;
}
