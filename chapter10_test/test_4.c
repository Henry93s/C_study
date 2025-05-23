/*
	도전 4.
	5,000원으로, dvd 한 편을 빌리고 남은 3,500 원이 있다.
	크림빵 : 500원, 새우깡 : 700원, 콜라 : 400원 을 각각 최소 1개씩 구매하고 잔돈을 하나도 남기지 않을 경우의 수를 모두 구하라
*/
#include <stdio.h>
int main(void) {
	int money = 5000; // 초기돈 5000원 선언 및 초기화
	int x, y, z; // 크림빵 x, 새우깡 y, 콜라 z 갯수
	money -= 1500; // dvd 한 편 빌리고 남은 돈 계산 : 3500 원

	printf("당신이 소유하고 있는 금액 : % d\n", money);

	for (x = 1; 500 * x <= money; x++) { // 크림빵 최소 1개
		for (y = 1; 700 * y <= money; y++) { // 새우깡 최소 1개
			for (z = 1; 400 * z <= money; z++) { // 콜라 최소 1개
				if (500 * x + 700 * y + 400 * z == money) {
					printf("크림빵 %d개, 새우깡 %d개, 콜라 %d개\n", x, y, z);
				}
			}
		}
	}
	printf("어떻게 구입하시겠습니까?\n");
	
	return 0;
}