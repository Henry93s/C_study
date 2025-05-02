// #ifdef...#endif : 정의되었다면 ... 동작 시키게 하는 매크로

// #ifndef...#endif : 정의되지 않았다면 ... 동작 시키게 하는 매크로
// -> 헤더파일이나 매크로의 중복 삽입을 방지할 때 많이 사용
// ==> 헤더파일 만들 때 다른 헤더파일과 겹치지 않게 거의 많이 사용함

// #if, ifdef, ifndef 활용
// 실행 환경에 따라 실행할 코드와 실행하지 않을 코드를 구분할 때 많이 사용 !

#include <stdio.h>
#define HIT_NUM 6

int main() {
#if HIT_NUM==5 // if 코드와 다른 점은 전처리 동작으로 인해 코드 자체가 컴파일 되지 않거나, 컴파일됨.
	puts("매크로 상수 HIT_NUM은 현재 5입니다.");
#elif HIT_NUM==6 // elif : else if 와 같음
	puts("매크로 상수 HIT_NUM은 현재 6입니다.");
#else
	puts("매크로 상수 HIT_NUM은 현재 5가 아닙니다.");
#endif

	return 0;
}