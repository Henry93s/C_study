#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

// 스레드 처리 함수
static void* clnt_connection(void* arg);
int sendData(FILE* fp, char* ct, char* filename);
void sendOk(FILE* fp);
void sendError(FILE* fp);

int main(int argc, char** argv){
	int ssock;
	pthread_t thread;
	struct sockaddr_in servaddr, cliaddr;
	unsigned int len;

	// 프로그램을 시작할 때 서버를 위한 포트 번호를 입력받음
	if(argc != 2){
		printf("usage : %s <port>\n", argv[0]);
		return -1;
	}

	// 서버를 위한 소켓을 생성
	ssock = socket(AF_INET, SOCK_STREAM, 0);
	if(ssock == -1){
		perror("socket()");
		return -1;
	}

	// 입력받는 포트 번호를 이용해서 서비스를 운영체제에 등록
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = (argc != 2) ? htons(8000) : htons(atoi(argv[1]));
	if(bind(ssock, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
		perror("bind()");
		return -1;
	}

	// 최대 10대의 클라이언트의 동시 접속을 처리할 수 있도록 큐를 생성
	if(listen(ssock, 10) == -1){
		perror("listen()");
		return -1;
	}

	while(1){
		char mesg[BUFSIZ];
		int csock;
		// 클라이언트 요청을 기다림
		len = sizeof(cliaddr);
		csock = accept(ssock, (struct sockaddr*)&cliaddr, &len);
		// 네트워크 주소를 문자열로 변경
		inet_ntop(AF_INET, &cliaddr.sin_addr, mesg, BUFSIZ);
		printf("Client IP : %s:%d\n", mesg, ntohs(cliaddr.sin_port));

		// 클라이언트 요청이 들어오면 스레드를 생성하고 클라이언트 요청을 처리
		pthread_create(&thread, NULL, clnt_connection, &csock);
		// pthread_join(thread, NULL); // 연속적인 클라이언트 처리
	}

	return 0;
}

void* clnt_connection(void* arg){
	// 스레드를 통해서 넘어온 arg를 int 형의 파일 디스크립터로 변환
	int csock = *((int*)arg);
	FILE* clnt_read, *clnt_write;
	char reg_line[BUFSIZ], reg_buf[BUFSIZ];
	char method[BUFSIZ], type[BUFSIZ];
	char filename[BUFSIZ], *ret;

	// 파일 디스크립터를 FILE 스트림으로 변환
	clnt_read = fdopen(csock, "r");
	clnt_write = fdopen(dup(csock), "w");

	// 한 줄의 문자열을 읽고 reg_line 변수에 저장
	fgets(reg_line, BUFSIZ, clnt_read);
	// reg_line 변수에 문자열을 화면에 출력
	fputs(reg_line, stdout);
	// ' ' 문자로 reg_line 을 구분해서 요청 라인의 내용(메소드)을 분리
	ret = strtok(reg_line, "/ ");
	strcpy(method, (ret != NULL) ? ret : "");

	// POST 메소드일 경우 처리
	if(strcmp(method, "POST") == 0){
		sendOk(clnt_write);
		goto END;
		// GET 메소드가 아닐 경우 처리
	}else if(strcmp(method, "GET") != 0){
		sendError(clnt_write);
		goto END;
	}

	// 요청 라인에서 path 를 가져옴
	ret = strtok(NULL, " ");
	
	strcpy(filename, (ret != NULL) ? ret: "");
	// 경로가 슬래시 로 시작될 경우 / 제거
	if(filename[0] == '/'){
		for(int i=0, j=0;i < BUFSIZ; i++,j++){
			if(filename[0] == '/') j++;
			filename[i] = filename[j];
			if(filename[j] == '\0') break;
		}
	}

	// 메시지 헤더를 읽고 화면에 출력 후 나머지 무시
	do {
		fgets(reg_line, BUFSIZ, clnt_read);
		fputs(reg_line, stdout);
		strcpy(reg_buf, reg_line);
		char* str = strchr(reg_buf, ':');
	}while(strncmp(reg_line, "\r\n", 2)); // 요청 헤더는 '\r\n' 으로 끝난다

	// 파일 이름을 이용해 클라이언트로 파일의 내용을 보냄
	sendData(clnt_write, type, filename);

END:
	// 파일 스트림 닫기
	fclose(clnt_read);
	fclose(clnt_write);

	// 스레드 종료
	pthread_exit(0);

	return (void*)NULL;
}

int sendData(FILE* fp, char* ct, char* filename){
	// 클라이언트로 보낼 성공에 대한 응답 메시지
	char protocol[] = "HTTP/1.1 200 OK\r\n";
	char server[] = "Server:Netscape-Enterprise/6.0\r\n";
	char cnt_type[] = "Content-Type:text/html\r\n";
	char end[] = "\r\n"; // 응답 헤더 끝은 항상 \r\n
	char buf[BUFSIZ];
	int fd, len;

	fputs(protocol, fp);
	fputs(server, fp);
	fputs(cnt_type, fp);
	fputs(end, fp);

	fd = open(filename, O_RDWR);
	do{
		// 파일을 읽고 클라이언트로 보냄
		len = read(fd, buf, BUFSIZ);
		fputs(buf, fp);
	}while(len == BUFSIZ);

	// 파일 닫기
	close(fd);

	return 0;
}

void sendOk(FILE* fp){
	// 클라이언트에 보낼 성공에 대한 HTTP 응답 메시지
	char protocol[] = "HTTP/1.1 200 OK\r\n";
	char server[] = "Server: Netscape-Enterprise/6.0\r\n\r\n";
	fputs(protocol, fp);
	fputs(server, fp);
	fflush(fp);
}

void sendError(FILE* fp){
	// 클라이언트로 보낼 실패에 대한 HTTP 응답 메시지
	char protocol[] = "HTTP/1.1 400 Bad Request\r\n";
	char server[] = "Server: Netscape-Enterprise/6.0\r\n";
	char cnt_len[] = "Content-Length:1024\r\n";
	char cnt_type[] = "Content-Type:text/html\r\n\r\n";

	// 화면에 표시될 HTML 내용
	char content1[] = "<html><head><title>BAD Connection</title></head>";
	char content2[] = "<body><font size=+5>Bad Request</font></body></html>";

	printf("send_error\n");
	fputs(protocol, fp);
	fputs(server, fp);
	fputs(cnt_len, fp);
	fputs(cnt_type, fp);
	fputs(content1, fp);
	fputs(content2, fp);
	fflush(fp);
}
