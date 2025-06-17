#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define UDP_PORT	5100


int main(int argc, char** argv){
	int sockfd, n;
	socklen_t clisize;
	struct sockaddr_in servaddr, cliaddr;
	char mesg[BUFSIZ];

	if(argc != 2) {
		printf("Usage : %s <IP address\n", argv[0]);
		return -1;
	}

	// UDP 를 위한 소켓 생성
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	// 서버 주소와 포트 번호를 이용해 주소 설정
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	// 문자열을 네트워크 주소로 변경 -> inet_pton()
	// ipv4 주소 이므로 첫 인자로 AF_INET 사용
	inet_pton(AF_INET, argv[1], &(servaddr.sin_addr.s_addr));
	servaddr.sin_port = htons(UDP_PORT);

	// 키보드로부터 문자열을 받아 서버로 전송
	do{
		fgets(mesg, BUFSIZ, stdin);
		sendto(sockfd, mesg, strlen(mesg), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
		clisize = sizeof(cliaddr);

		// 서버로 부터 데이터를 받아 화면에 출력
		n = recvfrom(sockfd, mesg, BUFSIZ, 0, (struct sockaddr*)&cliaddr, &clisize);
		mesg[n] = '\0';
		fputs(mesg, stdout);
	// 클라이언트에서 q 입력 시 서버도 함께 종료됨
	}while(strncmp(mesg, "q", 1));

	close(sockfd);

	return 0;
}
