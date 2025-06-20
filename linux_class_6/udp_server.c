#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define UDP_PORT	5100

int main(int argc, char** argv){
	int sockfd, n;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t len;
	char mesg[1000];

	// UDP 를 위한 소켓 생성
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	// 접속되는 클라이언트를 위한 주소 설정 후 운영체제에 서비스 등록
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	// IP 주소와 PORT 번호를 네트워크 순서로 엔디안을 변경 :htonl(), htons()
	// 서버가 동적으로 바뀌더라도 사용하기 쉽도록 INADDR_ANY
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(UDP_PORT);
	bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

	// 클라이언트로부터 메시지를 받아서 다시 클라이언트로 전송
	do{
		len = sizeof(cliaddr);
		n = recvfrom(sockfd, mesg, 1000, 0, (struct sockaddr*)&cliaddr, &len);
		sendto(sockfd, mesg, n, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));

		mesg[n] = '\0';
		printf("Received data : %s\n", mesg);
	}while(strncmp(mesg, "q", 1));

	// 사용 끝난 소켓 닫기
	close(sockfd);

	return 0;
}

