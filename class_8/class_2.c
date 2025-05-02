// 바이너리 데이터 집합체인 구조체 변수의 입출력
#include <stdio.h>
typedef struct fren {
	char name[10];
	char sex;
	int age;
} Friend;

int main() {
	Friend myfren1;
	Friend myfren2;

	// write
	FILE* fp = fopen("friend.bin", "wb"); // 구조체 변수를 저장하기 위해서 바이너리 모드로 파일 개방
	printf("이름, 성별, 나이 순 입력: ");
	scanf_s("%s %c %d", myfren1.name, 10, &(myfren1.sex), 1, &(myfren1.age));
	// fwrite 함수는 데이터를 바이트 단위로 저장하기 때문에
	// 구조체 변수를 한번에 저장할 수 있음.
	fwrite((void*)&myfren1, sizeof(myfren1), 1, fp);
	fclose(fp);

	// read
	fopen_s(fp, "friend.bin", "rb"); 
	// fread 도 구조체 변수를 한번에 읽을 수 있음.
	fread((void*)&myfren2, sizeof(myfren2), 1, fp);
	printf("%s %c %d\n", myfren2.name, myfren2.sex, myfren2.age);
	fclose(fp);

	return 0;
}