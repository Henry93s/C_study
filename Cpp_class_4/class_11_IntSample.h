#ifndef _INTSAMPLE_H // 중복 선언 방지를 위한 매크로 ifndef ~ endif
#define _INTSAMPLE_H

#include <iostream> // 기본 iostream include 도 보통 헤더파일에 작성
using namespace std;

class IntSample { // 보통 클래스 선언부는 헤더파일로 생성한다 !
public:
	void ShowScore();
	void setScore(const int s);
	int getScore();

private:
	int Score;
};

#endif