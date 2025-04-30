// class_3.c : fflush -> 출력버퍼를 비우는 함수
#include <stdio.h>
void ClearLineFromReadBuffer() { // 버퍼에서 '\n' 이 나올 때까지 문자를 읽어들임
	while (getchar() != '\n');
}
int main() {
	char perID[7];
	char name[10];

	fputs("주민번호 앞 6자리 입력: ", stdout);
	fgets(perID, sizeof(perID), stdin); // 입력받을 때 enter 키까지 입력됨
	// 수정 -> 버퍼에서 개행문자를 읽어드리는 함수 사용
	ClearLineFromReadBuffer(); // 입력 버퍼 지우기

	fputs("이름 입력: ", stdout); 
	fgets(name, sizeof(name), stdin); // 버퍼에 남아있는 \n 이 입력됨

	printf("주민번호: %s\n", perID);
	printf("이름: %s\n", name);

	return 0;
}

