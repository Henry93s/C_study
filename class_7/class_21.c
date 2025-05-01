// 문자열 방식의 데이터 입출력 문제 522p 문제 1
#include <stdio.h>
#include <string.h>
typedef struct person {
	char name[20];
	char num[50];
	char phone[50];
	char food[50];
	char hobby[50];
}Person;

int main() {
	FILE* src = fopen("mystory.txt", "wt");
	Person person;
	
	fgets(person.name, 20, stdin);
	fgets(person.num, 50, stdin);
	fgets(person.phone, 50, stdin);
	// person.phone[strcspn(person.phone, "\n")] = '\0';
	// fgets 로 입력 완료
	// 마지막 휴대폰 입력만 휴대폰 문자열(fgets 로 읽었으므로) 의 마지막 글자
	// 개행문자를 찾고 널문자로 교체한다. (문제 2로 인해 생략)
	
	// src 파일 포인터 주소 즉 파일에 각각 입력한 이름, 주민번호, 전화번호를
	// 파일에 작성한다.
	fputs(person.name, src);
	fputs(person.num, src);
	fputs(person.phone, src);

	fclose(src);

	// 문제 2. 데이터 추가 
	fopen_s(src, "mystory.txt", "a");
	fgets(person.food, 50, stdin);
	fgets(person.hobby, 50, stdin);
	person.hobby[strcspn(person.hobby, "\n")] = '\0';

	fputs(person.food, src);
	fputs(person.hobby, src);

	fclose(src);

	return 0;
}
// fgets 가 아닌 scanf 를 이용했을 땐 각각 맴버에 #을 먼저 넣고
// scanf 시 멤버의 첫번째 주소로 받는다.
/*
#include <stdio.h>

typedef struct {
  char name[9];
  char jumin[16];
  char phoneno[15];
} Person;

int main(void)
{
  Person me;
  FILE *fp;

  printf("정보를 입력하세요.\n");
  me.name[0] = '#'; me.jumin[0] = '#'; me.phoneno[0] = '#';
  printf("이름 : "), scanf("%s", &(me.name[1]));
  printf("주민등록번호 : "), scanf("%s", &(me.jumin[1]));
  printf("전화번호 : "), scanf("%s", &(me.phoneno[1]));

  fp = fopen("mystory.txt", "wt");
  fwrite(&me, sizeof(Person), 1, fp);
  fclose(fp);

  return 0;
}
*/