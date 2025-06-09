#include <stdio.h>
#include <stdlib.h>
// wiringPi 라이브러리를 위한 헤더 파일
#include <wiringPi.h>

int ledControl(int gpio){
  int i;

  // Pin 출력 설정
  pinMode(gpio, OUTPUT);

  for(i=0;i<5;i++){
    // HIGH(1) 값을 출력 : LED 켜기
    digitalWrite(gpio,HIGH);
    // 1초 동안 딜레이
    delay(1000);
    // LOW(0) 값을 출력 : led 끄기
    digitalWrite(gpio, LOW);
    delay(1000);
  }

  return 0;
}

int main(int argc, char **argv){
  int gno;

  if(argc < 2){
    printf("Usage: %s GPIO_NO\n", argv[0]);
    return -1;
  }

  // gpio readall 시 기존 18번 핀이 wiringPi 핀 번호로는 1 이므로 인자로 1 로 실행한다.
  gno = atoi(argv[1]);
  // wiringPi 초기화
  wiringPiSetup();
  ledControl(gno);

  return 0;
}
