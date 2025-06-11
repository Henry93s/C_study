#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv){
	int n, in1, in2, out;
	char buf[1024];
	
	if(argc < 3){
		write(2, "Usage: copy file1 file2\n", 25);
		return -1;
	}

	// 두 번째, 세 번째 인자로 병합할 2개의 파일 이름을 받는다.
	if((in1 = open(argv[1], O_RDONLY)) < 0){
		perror(argv[1]);
		return -1;
	}
	if((in2 = open(argv[2], O_RDONLY)) < 0){
		perror(argv[2]);
		return -1;
	}

	// 네 번째 인자로 병합해서 만들어질 새 파일의 이름을 받는다.
	if((out = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0){
		perror(argv[3]);
		return -1;
	}
	// 첫 파일을 합쳐질 병합 파일에 복사
	while((n = read(in1, buf, sizeof(buf))) > 0){
		write(out, buf, n);
	}
	// 두 번째 파일과 구분을 위해 개행 문자를 병합 파일에 작성
	write(out, "\n", 1);
	// 검증 시 ./merge merge.c file.c merge_copy.c 로 병합됨을 확인
	// 두 번째 파일을 병합 파일에 복사
	while((n = read(in2, buf, sizeof(buf))) > 0){
		write(out, buf, n);
	}

	close(out);
	close(in1);
	close(in2);

	return 0;
}
