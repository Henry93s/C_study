#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define TCP_PORT    5100
// 한 번에 처리할 최대 이벤트 수
#define MAX_EVENT   32
// 동시 처리할 수 있는 최대 클라이언트 수
#define MAX_CLIENT  100

// 소켓 파일 디스크립터를 논블로킹 모드 설정
void setnonblocking(int fd){
	// 현재 설정을 가져옴
    int opts = fcntl(fd, F_GETFL);
	// 논블로킹 플래그 추가
    opts |= O_NONBLOCK;
	// 설정 적용
    fcntl(fd, F_SETFL, opts);
}

int main(int argc, char** argv){
	// ssock, csock : 서버 소켓, 클라이언트 소켓
	// epfd, nfds : epoll fd, 이벤트 개수
    int ssock, csock, epfd, nfds;
	// client 주소 길이
    socklen_t clen;
    struct sockaddr_in servaddr, cliaddr;
	// epoll 이벤트 구조체
    struct epoll_event ev, events[MAX_EVENT];
    char mesg[BUFSIZ];

    int client_fd[MAX_CLIENT] = {0}; // 클라이언트 소켓 목록
    int client_count = 0;

	// 1. 서버 소켓 생성(TCP)
    if((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket()");
        return -1;
    }

	// 2. 서버 소켓을 논블로킹 모드로 설정
    setnonblocking(ssock);

	// 3. 서버 주소 구조체 초기화 및 설정
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(TCP_PORT);

	// 4. 서버 소켓에 주소 바인딩
    if(bind(ssock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        perror("bind()");
        return -1;
    }

	// 5. 클라이언트 접속 대기 큐 생성
    if(listen(ssock, 8) < 0){
        perror("listen()");
        return -1;
    }

	// 6. epoll 인스턴스 생성
    epfd = epoll_create(MAX_EVENT);
    if(epfd == -1){
        perror("epoll_create()");
        return -1;
    }

	// 7. 서버 소켓을 epoll 에 등록(클라이언트 연결 감시용)
    ev.events = EPOLLIN; // 읽기 이벤트 감지
    ev.data.fd = ssock;
    if(epoll_ctl(epfd, EPOLL_CTL_ADD, ssock, &ev) == -1){
        perror("epoll_ctl() ssock");
        return -1;
    }

	// 8. 이벤트 루프 시작
    while(1){
		// 9. epoll 로부터 이벤트 대기(무한 대기)
        nfds = epoll_wait(epfd, events, MAX_EVENT, -1);
        if(nfds == -1){
            perror("epoll_wait()");
            break;
        }

		// 10. 발생한 이벤트 개수만큼 반복처리
        for(int i = 0; i < nfds; i++){
            int fd = events[i].data.fd;

            // 11. 서버 소켓에 이벤트가 발생하면 새 클라이언트 접속
            if(fd == ssock){
                clen = sizeof(cliaddr);
                csock = accept(ssock, (struct sockaddr*)&cliaddr, &clen);
                if(csock > 0){
					// 새 클라이언트 소켓을 논블로킹으로 설정
                    setnonblocking(csock);

					// 클라이언트 소켓을 epoll 에 등록
                    ev.events = EPOLLIN | EPOLLET;
                    ev.data.fd = csock;
                    epoll_ctl(epfd, EPOLL_CTL_ADD, csock, &ev);

					// 클라이언트 목록에 추가
                    client_fd[client_count++] = csock;

                    inet_ntop(AF_INET, &cliaddr.sin_addr, mesg, BUFSIZ);
                    printf("Client connected: %s\n", mesg);
                }
            }
            // 12. 기존 클라이언트로부터 데이터 수신
            else if(events[i].events & EPOLLIN){
                memset(mesg, 0, sizeof(mesg));
                int n = read(fd, mesg, sizeof(mesg));
                
				// 13. 연결 종료 or 오류 발생 시
				if(n <= 0){
                    // 연결 종료 처리
                    close(fd);
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                    printf("Client disconnected: %d\n", fd);

                    // client_fd 목록에서 제거
                    for(int j = 0; j < client_count; j++){
                        if(client_fd[j] == fd){
                            client_fd[j] = client_fd[client_count - 1];
                            client_fd[client_count - 1] = 0;
                            client_count--;
                            break;
                        }
                    }
                } else {
					// 14. 정상적으로 메시지를 수신했을 경우
                    printf("Received: %s", mesg);

                    // 15. 브로드캐스팅: 모든 클라이언트에게 메시지 전송
                    for(int j = 0; j < client_count; j++){
                        if(client_fd[j] != fd){ // 자기 자신 제외해도 됨
                            char send_msg[BUFSIZ];
                            snprintf(send_msg, sizeof(send_msg), "Client_fd [%d]: %s", fd, mesg);
                            write(client_fd[j], send_msg, strlen(send_msg));
                        }
                    }
                }
			}
		}
	}

	// 16. 서버 소켓 종료
	close(ssock);
	return 0;
}

