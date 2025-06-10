#include <wiringPi.h>
#include <stdio.h>

#define SW	5 // GPIO 24
#define CDS	0 // GPIO 17
#define LED	1 // GPIO 18

int cdsControl(){
	int i;
	pinMode(SW, INPUT); // Pin 모드를 입력으로 설정
	pinMode(CDS, INPUT); // Pin 모드를 입력으로 설정
	pinMode(LED, OUTPUT); // Pin 모드를 출력으로 설정

	// 조도 센서 검사를 위해 무한 루프 실행
	for(;;){
		// 빛이 HIGH(감지) 되면
		if(digitalRead(CDS) == HIGH){
			digitalWrite(LED, HIGH); // LED 켜기
			delay(1000);
			digitalWrite(LED, LOW); // LED 끄기
		}
	}

	return 0;
}

int main(){
	wiringPiSetup();
	// 조도 센서 사용을 위한 함수 호출
	cdsControl();
	return 0;
}
