#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>

void ledPwmControl(int gpio){
	// Pin 의 출력 설정
	pinMode(gpio, OUTPUT);
	// PWM 의 범위 설정
	// 초기 밝기 : 0, 범위 : 255(최대 밝기) 로 0~255 범위 내에서 조절
	softPwmCreate(gpio, 0, 255);

	// 10000 회 반복 * 5 밀리초 = 50000 밀리초 = 50초동안 밝기 조절 출력됨
	for(int i=0;i<10000;i++){
		// PWM 값을 출력: LED 켜기
		// i 값을 0 부터 255 까지 범위로 계속 반복 : 밝기가 밝아졌다가 어두워지는 효과
		softPwmWrite(gpio, i&255);
		delay(5);
	}
	
	// 50초 후 LED 끄기
	softPwmWrite(gpio, 0);
}

int main(int argc, char **argv){
	int gno;

	if(argc < 2){
		printf("Usage : %s GPIO_NO\n", argv[0]);
		return -1;
	}
	gno = atoi(argv[1]);
	// wiringPi 초기화
	wiringPiSetup();
	ledPwmControl(gno);

	return 0;
}

