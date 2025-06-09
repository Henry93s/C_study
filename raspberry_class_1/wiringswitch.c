#include <wiringPi.h>
#include <stdio.h>

// GPI024
#define SW	5
// GPI018
#define LED	1

int switchControl(){
	int i;
	// Pin 모드를 입력으로 설정
	pinMode(SW, INPUT);
	pinMode(LED, OUTPUT);

	// 스위치의 확인을 위해 무한 루프를 수행한다.
	for(;;){
		// Push 버튼이 눌러지면 (low)
		if(digitalRead(SW) == LOW){
			// LED 켜기
			digitalWrite(LED, HIGH);
			delay(1000);
			// LED 끄기
			digitalWrite(LED, LOW);
		}
		// ctrl + c 등 이베트를 감지하기 위해 잠시 쉼
		delay(10);
	}
	return 0;
}

int main(int argc, char **argv){
	wiringPiSetup();
	// 스위치 사용을 위한 함수
	switchControl();
	return 0;
}

