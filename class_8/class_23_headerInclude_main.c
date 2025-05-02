#include <stdio.h>

int main(void) 
#include "header1.h" // => { puts("Hello world!");
#include "header2.h" // => return 0; }
// 위 헤더 파일을 include 했기 떄문에 헤더파일들을 단순히 가져와서 치환한다.

// #include <~> : 표준 헤더 파일
// #include "~" : 사용자 정의 헤더 파일