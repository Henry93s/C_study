#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define TCP_PORT        5100

int main(int argc, char** argv){
	// 서버 소켓 디스크립터  
	int ssock;
	// 클라이언트 주소 길이
	socklen_t clen;
	// 수신된 바이트 수
	int n;
	
	// 서버, 클라이언트 주소 구조체
	struct sockaddr_in servaddr, cliaddr;
	char mesg[BUFSIZ];

	// select() 를 위한 파일 디스크립터 집합
	fd_set readfd;
	int maxfd, client_index, start_index;
	// 최대 5개의 클라이언트 소켓 저장
	int client_fd[5] = {0};
	
	// 1. 서버 소켓 생성
	if((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket()");
		return -1;
	}

	// 2. 서버 주소 정보 설정
	memset(&servaddr, 0, sizeof(servaddr));
	// IPv4 사용
	servaddr.sin_family = AF_INET;
	// 모든 인터페이스 접속 허용
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	// 포트 설정
	servaddr.sin_port = htons(TCP_PORT);
	
	// 3. 소켓에 주소 바인딩
	if(bind(ssock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
		perror("bind()");
        return -1;
	}
	
	// 4. 클라이언트 접속 요청 대기
	if(listen(ssock, 8) < 0){
		perror("listen()");
        return -1;
	}
	
	// 5. 초기화
	// fd_set 초기화
	FD_ZERO(&readfd);
	// 최대 소켓 번호 초기값은 서버 소켓
	maxfd = ssock;
	// 현재 접속한 클라이언트 수
	client_index = 0;
	
	// 6. 메인 이벤트 루프
	do{
	  // 매 루프마다 fd_set 초기화
      FD_ZERO(&readfd);
	  // 서버 소켓을 fd 리스트에 추가 
      FD_SET(ssock, &readfd);
	
      maxfd = ssock;
      for(start_index = 0; start_index < client_index; ++start_index){
		  if (client_fd[start_index] > 0) {
			  // 클라이언트 소켓 추가
			  FD_SET(client_fd[start_index], &readfd);
              if(client_fd[start_index] > maxfd){
				  // maxfd 갱신
                  maxfd = client_fd[start_index];
              }
          }
      }
	  // select() 함수에서는 maxfd+1 필요
	  // select() 는 0부터 maxfd-1 까지의 fd 를 검사하기 때문
      maxfd = maxfd + 1;

	  // 7. 읽기 가능한 소켓이 생길 때까지 블로킹
      select(maxfd, &readfd, NULL, NULL, NULL);

	  // 8. 새 클라이언트 연결 감지
      if(FD_ISSET(ssock, &readfd)){
		  clen = sizeof(struct sockaddr_in);
          // 클라이언트 연결 수락
		  int csock = accept(ssock, (struct sockaddr*)&cliaddr, &clen);

          if(csock < 0){
              perror("accept()");
              return -1;
          } else {
              // 연결된 클라이언트IP 주소 출력
			  inet_ntop(AF_INET, &cliaddr.sin_addr, mesg, BUFSIZ);
              printf("Client is connected : %s\n", mesg);
                
			  // 새 클라이언트 소켓 저장
			  client_fd[client_index++] = csock;
              // 이 loop 에서는 새 클라이언트만 처리  
			  continue;
          }

		  // 최대 5명 제한
          if(client_index == 5) break;
        }

	  	// 9. 기존 클라이언트로부터 메시지 수신 처리
        for(start_index = 0; start_index < client_index; start_index++){
		  // 클라이언트 소켓 FD
          int cfd = client_fd[start_index];
		  // 해당 클라이언트 소켓에 데이터 도착 감지
          if(FD_ISSET(cfd, &readfd)){
			  // 버퍼 초기화
              memset(mesg, 0, sizeof(mesg));
              // 메시지 수신
			  if((n = read(cfd, mesg, sizeof(mesg))) > 0) {
				  // 수신 메시지 출력
				  printf("Client_fd [%d]: %s", cfd, mesg);

                  // 메시지가 "q"일 경우 해당 클라이언트만 종료
                  if (strncmp(mesg, "q", 1) == 0) {
                      close(cfd);
                      // fd 리스트에서 제거
					  FD_CLR(cfd, &readfd);
                      // 클라이언트 리스트에서 제거  
					  client_fd[start_index] = 0;  
					  printf("Client_fd [%d] quit.\n", cfd);
                        
					  continue; // 다른 클라이언트 계속 처리
                  }

                  // 10. 다른 클라이언트에게 메시지 전파(브로드캐스팅)
                  for(int j = 0; j < client_index; j++) {
                      if(client_fd[j] != 0) {
                          char send_msg[BUFSIZ];
                          // 메시지 앞에 보낸 클라이언트 번호 추가
						  snprintf(send_msg, sizeof(mesg), "Client_fd [%d] : %s",cfd, mesg);

                          // 각 클라이언트에게 메시지 전송  
						  write(client_fd[j], send_msg, strlen(send_msg));
                      }
                  }
              }
          }
      }
	  // 서버는 계속 실행
	} while(1);
	
	// 서버 종료 시 소켓 닫기
	close(ssock);
	return 0;
}

