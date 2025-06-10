#include <stdio.h>
#include <softTone.h>
#include <wiringPi.h>

// GPIO25
#define SPKR	6
// 학교종 전체 계이름 수
#define TOTAL	32

// 계이름
int notes[]={
	    391,391,440,440,391,391,330,330, \
		391,391,330,294,294,0, \
		391,391,440,440,391,391,330,330, \
		391,330,294,330,262,262,262,0
};

int musicPlay(){
	int i;
	// 톤 출력을 위한 GPIO 설정
	softToneCreate(SPKR);
	for(i=0;i<TOTAL;i++){
		// 톤 출력 : 학교종 연주
		softToneWrite(SPKR, notes[i]);
		// 음 전체 길이만큼 딜레이
		delay(280);
	}
	return 0;
}

int main(){
	wiringPiSetup();
	musicPlay();
	return 0;
}
