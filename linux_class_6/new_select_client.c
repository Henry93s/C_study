#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define TCP_PORT        5100

int main(int argc, char** argv){
	// 서버와 연결할 소켓 디스크립터
	int ssock;
	// 서버 주소 구조체
    struct sockaddr_in servaddr;
    char mesg[BUFSIZ];

    if(argc < 2){
        printf("Usage : %s IP_ADDRESS\n", argv[0]);
        return -1;
    }

    // 1. 소켓 생성 : TCP 스트림 소켓
    if((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket()");
        return -1;
    }

    // 2. 소켓이 접속할 주소 지정
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
	// 문자열 IP를 네트워크 바이트 순서로 변환
    inet_pton(AF_INET, argv[1], &(servaddr.sin_addr.s_addr));
    servaddr.sin_port = htons(TCP_PORT);

    // 3. 지정한 주소로 접속 요청
    if(connect(ssock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        perror("connect()");
        return -1;
    }

	// select() readfd fd 리스트 set
    fd_set readfd;
	// select 첫 번째 인자로 들어갈 최대 fd + 1
    int maxfd;
	// 수신 데이터 길이 저장
    int n;

    do{
		// 메시지 버퍼 초기화
        memset(mesg, 0, BUFSIZ);
		// fd 리스트 초기화
        FD_ZERO(&readfd);
		// 표준 입력을 fd 리스트에 추가
        FD_SET(0, &readfd);       // 표준 입력
		// 서버 소켓을 fd 리스트에 추가
        FD_SET(ssock, &readfd);   // 소켓

		// select()의 첫 번째 인자는 감시할 fd 중 가장 큰 값 + 1이어야 함
        // -> select는 0부터 maxfd-1까지의 fd만 확인하기 때문
        maxfd = ssock > 0 ? ssock + 1 : 1;
		
		// 감시 중인 fd 중 읽을 수 있는 것이 있는지 확인
        if(select(maxfd, &readfd, NULL, NULL, NULL) < 0){
            perror("select()");
            break;
        }

        // 사용자 입력 처리
        if(FD_ISSET(0, &readfd)){
            fgets(mesg, BUFSIZ, stdin);
            // 서버에 메시지 전송
			if(send(ssock, mesg, strlen(mesg), 0) <= 0){
                perror("send()");
                break;
            }
        }

        // 서버로부터 응답 처리
        if(FD_ISSET(ssock, &readfd)){
			// 메시지 수신
            n = recv(ssock, mesg, BUFSIZ, 0);
            if(n <= 0){
                perror("recv()");
                break;
            }
			// 문자열 종료 널 문자
            mesg[n] = '\0';
			
			// 받은 메시지 출력
			printf("%s", mesg);
        }
		// q 입력 시 (해당 클라이언트만) 종료
    } while(strncmp(mesg, "q", 1) != 0);

	// 자신 소켓(현재 코드 입장에서는 해당 소켓이 서버, 서버에서 받으면 클라이언트)  닫기
    close(ssock);
    return 0;
}

