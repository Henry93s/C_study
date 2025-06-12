#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h> // 디렉터리 조작 함수를 위한 헤더
#include <pwd.h> // getpwuid 함수(uid 를 이용하여 사용자 이름 구하기) 를 위한 헤더
#include <grp.h> // getgrgid 함수(gid 를 이용하여 그룹 이름 구하기) 를 위한 헤더
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int listDir(char* arg){
	// 디렉터리 조작을 위한 스트림
	DIR* pdir;
	// 디렉터리의  항목을 위한 구조체
	struct dirent* dirt;
	// 파일의 정보를 위한 구조체
	struct stat statBuf;
	// 사용자 이름 출력을 위한 변수
	struct passwd* username;
	// 그룹 이름 출력을 위한 변수
	struct group* groupname;
	// 시간 출력을 위한 변수
	struct tm* t;
	int i=0, count =0;
	char* dirName[255], buf[255], permission[11], mtime[20];

	// 변수 초기화
	memset(dirName, 0, sizeof(dirName));
	memset(&dirt, 0, sizeof(dirt));
	memset(&statBuf, 0, sizeof(statBuf));

	// 해당 디렉터리의 스트림 열기
	if((pdir = opendir(arg)) <= 0){
		perror("opendir");
		return -1;
	}

	// 디렉터리로 이동
	chdir(arg);
	// 현재 디렉터리의 절대 경로를 가져와 표시
	getcwd(buf, 255);
	printf("\n%s: Directory\n", arg);

	// 현재 디렉터리를 읽을 수 있으면 순환
	while((dirt = readdir(pdir)) != NULL){
		// 현재 디렉터리에 대한 정보 가져옴
		lstat(dirt->d_name, &statBuf);
		// 파일 종류 검사
		if(S_ISDIR(statBuf.st_mode)){
			permission[0]='d';
		}else if(S_ISLNK(statBuf.st_mode)){
			permission[0]='l';
		}else if(S_ISCHR(statBuf.st_mode)){
			permission[0]='c';
		}else if(S_ISBLK(statBuf.st_mode)){
			permission[0]='b';
		}else if(S_ISSOCK(statBuf.st_mode)){
			permission[0]='s';
		}else if(S_ISFIFO(statBuf.st_mode)){
			permission[0]='P';
		}else{
			permission[0]='-';
		}

		// 사용자에 대한 권한 검사
		permission[1]=statBuf.st_mode & S_IRUSR ? 'r' : '-';
		permission[2]=statBuf.st_mode & S_IWUSR ? 'w' : '-';
		permission[3]=statBuf.st_mode & S_IXUSR ? 'x' : 
					  statBuf.st_mode & S_ISUID ? 'S' : '-';

		// 그룹에 대한 권한 검사
		permission[4]=statBuf.st_mode & S_IRGRP ? 'r' : '-';
		permission[5]=statBuf.st_mode & S_IWGRP ? 'w' : '-';
		permission[6]=statBuf.st_mode & S_IXGRP ? 'x' :	
					  statBuf.st_mode & S_ISGID ? 'S' : '-';

		// 다른 사용자에 대한 권한 검사
		permission[7]=statBuf.st_mode & S_IROTH ? 'r' : '-';
		permission[8]=statBuf.st_mode & S_IWOTH ? 'w' : '-';
		permission[9]=statBuf.st_mode & S_IXOTH ? 'x' : '-';
		
		// 스티키 비트 설정
		if(statBuf.st_mode & S_IXOTH) {
			permission[9] = statBuf.st_mode & S_ISVTX ? 't' : 'x';
		}else{
			permission[9] = statBuf.st_mode & S_ISVTX ? 'T' : '-';
		}

		permission[10]='\0';
		
		// 디렉터리인지 검사
		if(S_ISDIR(statBuf.st_mode) == 1){
			if(strcmp(dirt->d_name, ".") && strcmp(dirt->d_name, "..")) {
				dirName[count] = dirt->d_name;
				count = count + 1;
			}
		}

		// uid 에서 사용자의 이름 획득
		username = getpwuid(statBuf.st_uid);
		// gid 에서 그룹의 이름 획득
		groupname = getgrgid(statBuf.st_gid);
		// 최근 수정된 시간 출력
		t = localtime(&statBuf.st_mtime);
		// 출력을 위한 서식화
		sprintf(mtime, "%01d월 %02d %2d:%02d",
				t->tm_mon + 1, t->tm_mday,
				t->tm_hour, t->tm_min);

		printf("%s %2d %7s %7s %9ld %s %s\n", permission, statBuf.st_nlink, username->pw_name, groupname->gr_name,
				statBuf.st_size, mtime, dirt->d_name);
	}

	// 다른 디렉터리에 대한 재귀 호출
	for(i = 0;i < count; i++){
		if(listDir(dirName[i]) == -1){
			break;
		}
	}

	printf("\n");
	// 열었던 디렉토리의 스트림을 닫음
	closedir(pdir);
	// 원래 디렉토리로 이동
	chdir("..");

	return 0;
}

int main(int argc, char **argv){
	if(argc < 2){
		fprintf(stderr, "Usage: %s directory_name.\n", argv[0]);
		return -1;
	}

	listDir(argv[1]);

	return 0;
}




