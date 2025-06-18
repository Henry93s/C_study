#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>

#define TCP_PORT    5100
#define MAX_EVENT   32

// fd 를 논블로킹 모드로 설정
void setnonblocking(int fd){
    int opts = fcntl(fd, F_GETFL);
    opts |= O_NONBLOCK;
    fcntl(fd, F_SETFL, opts);
}

int main(int argc, char** argv){
	// 서버 소켓 디스크립터
	int ssock;
	// 서버 주소 구조체
    struct sockaddr_in servaddr;
    char mesg[BUFSIZ];
	// epoll 이벤트 구조체
    struct epoll_event ev, events[MAX_EVENT];
    // epoll 파일 디스크립터, 이벤트 수
	int epfd, nfds;

	// 1. IP 주소 인자 확인
    if(argc < 2){
        printf("Usage : %s IP_ADDRESS\n", argv[0]);
        return -1;
    }

	// 2. 서버에 연결할 소켓 생성(TCP)
    if((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket()");
        return -1;
    }

	// 3. 소켓을 논블로킹 모드로 설정
    setnonblocking(ssock);

	// 4. 서버 주소 설정
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &(servaddr.sin_addr.s_addr));
    servaddr.sin_port = htons(TCP_PORT);

	// 5. 서버에 연결 요청
    if(connect(ssock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        if(errno != EINPROGRESS){
            perror("connect()");
            return -1;
        }
    }
	// 연결 결과 확인은 생략

    // 6. epoll 인스턴스 생성
    epfd = epoll_create(MAX_EVENT);
    if(epfd == -1){
        perror("epoll_create1()");
        return -1;
    }

    // 7. 서버 소켓을 epoll 에 등록(서버 메시지 수신용)
    ev.events = EPOLLIN;
    ev.data.fd = ssock;
    if(epoll_ctl(epfd, EPOLL_CTL_ADD, ssock, &ev) == -1){
        perror("epoll_ctl() ssock");
        return -1;
    }

    // 8. 표준 입력(STDIN)도 epoll에 등록(현재 사용자 입력 감지용)
    ev.events = EPOLLIN;
    ev.data.fd = STDIN_FILENO; // 0 번 디스크립터 : 표준 입력
    if(epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev) == -1){
        perror("epoll_ctl() stdin");
        return -1;
    }

	// 9. 이벤트 루프 시작
    while(1){
		// 10. epoll 대기 (입력 또는 서버 메시지 수신 대기)
        nfds = epoll_wait(epfd, events, MAX_EVENT, -1);
        if(nfds == -1){
            perror("epoll_wait()");
            break;
        }

		// 11. 발생 이벤트 수만큼 반복처리
        for(int i = 0; i < nfds; i++){
            // 사용자 입력 처리
            if(events[i].data.fd == STDIN_FILENO){
                memset(mesg, 0, BUFSIZ);
                if(fgets(mesg, BUFSIZ, stdin) == NULL){
                    perror("fgets()");
                    continue;
                }

                if(strncmp(mesg, "q", 1) == 0){
                    printf("Disconnected.\n");
                    close(ssock);
                    return 0;
                }

				// 12. 서버에 메시지 전송
                if(send(ssock, mesg, strlen(mesg), 0) <= 0){
                    perror("send()");
                }
            }
            // 13. 서버로부터 메시지 수신 처리
            else if(events[i].data.fd == ssock){
                memset(mesg, 0, BUFSIZ);
                int n = recv(ssock, mesg, BUFSIZ, 0);
                if(n <= 0){
                    perror("recv()");
                    close(ssock);
                    return -1;
                }
                mesg[n] = '\0'; // 수신 문자열 종료 처리(널문자)
				// 받은 메시지 출력
                printf("%s", mesg);
            }
        }
    }

	// 14. 소켓 정리
    close(ssock);
    return 0;
}
