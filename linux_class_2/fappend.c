#include <stdio.h>

int main(int argc, char **argv){
	int n;
	FILE* append, *target;
	char buf[BUFSIZ];

	// 명령행 인수를 복사할 파일명이 없는 경우에 에러를 출력하고 종료한다.
	if(argc != 3){
		fprintf(stderr, "Usage: fcopy file1 file2\n");
		return -1;
	}

	// 원본 파일을 추가 모드로 연다
	if((append = fopen(argv[1], "a")) == NULL){
		perror(argv[1]);
		return -1;
	}

	// 추가시킬 대상 파일을 읽기 모드로 연다
	if((target = fopen(argv[2], "r")) == NULL){
		perror(argv[2]);
		return -1;
	}

	// 테스트 시 ./fappend fappend_copy.c file.c 로 fappend_copy.c 에 file.c 내용이 추가됨을 확인함
	// 추가 파일 내용을 읽어서 원본 파일에 추가한다
	while((n = fread(buf, sizeof(char), BUFSIZ, target)) > 0){
		fwrite(buf, sizeof(char), n, append);
	}

	fclose(target);
	fclose(append);

	return 0;
}
