// 구조체와 문자열 함수 사용
#include <stdio.h>
#include <string.h>
struct person {
	char name[20];
	char phoneNum[20];
	int age;
};

int main(void) {
	struct person man1, man2;
	// ! 구조체 내부 문자열에 값을 넣는 방법
	// (man1.name = "안성준" 은 주소가 넘어가지 않았으므로 변경 불가 및 컴파일 에러))
	// -> 문자열 저장을 위해서는 strcpy_s() 또는 strncpy_s() 사용한다.
	strncpy_s(man1.name, sizeof(man1.name), "안성준", sizeof(man1.name));
	strncpy_s(man1.phoneNum, sizeof(man1.phoneNum), "010-1122-3344", sizeof(man1.phoneNum));
	man1.age = 23;
	/* strcpy 와 strncpy 차이 ! (다른 strn~ 도 동일)
		strcpy_s : (destination, destination size, source)
		strncpy_s : (destination, destination size, source, source size)
				source size: 복사할 문자열의 길이
	*/

	printf("이름 입력: ");
	scanf_s("%s", man2.name, sizeof(man2));
	printf("전화번호 입력: ");
	scanf_s("%s", man2.phoneNum, sizeof(man2.phoneNum));
	printf("나이 입력: ");
	scanf_s("%d", &man2.age);

	printf("이름 : %s\n", man1.name);
	printf("전화번호 : %s\n", man1.phoneNum);
	printf("나이 : %d\n", man1.age);
	printf("\n");

	printf("이름 : %s\n", man2.name);
	printf("전화번호 : %s\n", man2.phoneNum);
	printf("나이 : %d\n", man2.age);

	return 0;
}