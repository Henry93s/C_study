// malloc, calloc, realoc

// malloc, calloc, realoc 모두 성공하면 할당된 메모리 주소값, 실패시 NULL 반환

// malloc 의 경우 힙 영역에 할당할 (총 byte) 만 매개변수에 넣지만
// calloc 의 경우 힙 영역에 할당할 (block count, 각 block byte) 를 매개변수로 받는다.

// realoc 은 힙에 할당된 메모리 공간을 확장할 때 호출
// (메모리 주소, 총 byte) -> 총 byte 로 확장됨
// ==> 반환 케이스로 
// 1. 기존 malloc, calloc 으로 반환한 주소값과 같은 경우 : 정상
// 2. 기존 malloc, calloc 으로 반환한 주소값과 다른 경우 : 확장할 공간이
//	부족해서 다른 공간으로 확장 후 기존 값을 복사한 경우

