// 열거형 enum 의 정의와 의미
#include <stdio.h>
typedef enum syllable { // typedef 선언이 추가된 열거형의 정의
	Do = 1, Re = 2, Mi = 3, Fa = 4, So = 5, La = 6, Ti = 7
} Syllable;

void Sound(Syllable sy) {
	switch (sy)
	{
	case Do:
		puts("도는 하얀 도라지"); return;
	case Re:
		puts("레는 둥근 레코드"); return;
	case Mi:
		puts("미는 파란 미나리"); return;
	case Fa:
		puts("파는 예쁜 파랑새"); return;
	case So:
		puts("솔은 작은 솔방울"); return;
	case La:
		puts("라는 라디오고요"); return;
	case Ti:
		puts("시는 졸졸 시냇물"); return;
	default:
		break;
	}
	puts("다 함께 부르세~ 도레미파 솔라시도 솔 도~ 짠~");
}

int main() {
	Syllable tone;
	for (tone = Do;tone <= Ti;tone += 1) { // Do, Ti 는 상수이므로 1과 7과 동일
		// 단 열거형 enum 을 정의할 때 상수의 값을 정하지 않으면
		// ex 1. Do, Re. Mi, ... 일 때 0 부터 시작해서 1씩 증가한 값으로 결정된다.
		// ex 2. Do, Re, Mi=6, Fa, ... 일 때 0 1 6 7 로, 정의한 값 전에는 0 부터, 정의 후
		// 는 정의된 값에서 1씩 증가한 값으로 결정된다.
		Sound(tone);
	}

	return 0;
}