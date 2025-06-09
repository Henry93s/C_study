#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int ledControl(int gpio){
   int fd;
   char buf[BUFSIZ];

   // 해당 GPIO 디바이스 사용 준비
   fd = open("/sys/class/gpio/export", O_WRONLY);
   sprintf(buf, "%d", gpio);
   write(fd, buf, strlen(buf));
   close(fd);

   // GPIO 디바이스의 방향 설정
   sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
   fd = open(buf, O_WRONLY);
   // LED 를 위해 디바이스를 출력으로 설정 (입력은 in)
   write(fd, "out", 4);
   close(fd);

   // 디바이스에 값 출력
   sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
   fd = open(buf, O_WRONLY);
   write(fd, "1", 2);
   close(fd);

   // LED 확인을 위한 대기
   getchar();

   // 사용한 GPIO 디바이스 해제하기
   fd = open("/sys/class/gpio/unexport", O_WRONLY);
   sprintf(buf, "%d", gpio);
   write(fd, buf, strlen(buf));
   close(fd);

   return 0;
}

int main(int argc, char **argv){
   int gno;

   if(argc < 2){
	printf("Usage : %s GPIO_NO\n", argv[0]);
	return -1;
   }

   gno = atoi(argv[1]);
   ledControl(gno);

   return 0;
}
