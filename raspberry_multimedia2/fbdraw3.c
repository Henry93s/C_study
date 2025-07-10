#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#define FBDEVICE "/dev/fb0"

typedef unsigned char ubyte;
struct fb_var_screeninfo vinfo;	/* 프레임 버퍼 정보 처리를 위한 구조체 */

unsigned short makepixel(unsigned char r, unsigned char g, unsigned char b) {
    return (unsigned short)(((r>>3)<<11)|((g>>2)<<5)|(b>>3));
}

/* 점을 그린다. */
#if 1
static int drawpoint(int fd, int x, int y, unsigned short color)
{

    /* 색상 출력을 위한 위치 계산 : offset  = (X의_위치+Y의_위치x해상도의_넓이)x2  */
    int offset = (x + y*vinfo.xres)*2;
    lseek(fd, offset, SEEK_SET);
    write(fd, &color, 2);
    return 0;
}
#else
static void drawpoint(int fd, int x, int y, ubyte r, ubyte g, ubyte b)
{
    ubyte a = 0xFF;

    /* 색상 출력을 위한 위치를 구한다. */
    /* offset = (X의_위치 + Y의_위치 × 해상도의_넓이) × 색상의_바이트_수 */
    int offset = (x + y*vinfo.xres)*vinfo.bits_per_pixel/8.; 
    lseek(fd, offset, SEEK_SET);
    write(fd, &b, 1);
    write(fd, &g, 1);
    write(fd, &r, 1);
    write(fd, &a, 1);
}
#endif

#if 1
static void drawline(int fd, int start_x, int end_x, int y, unsigned short color){
	ubyte a = 0xFF;
	for(int x = start_x; x < end_x; x++){
		drawpoint(fd, x, y, color);
	}
}
#else
static void drawline(int fd, int start_x, int end_x, int y, ubyte r, ubyte g, ubyte b)
{
    ubyte a = 0xFF;

    /* 색상 출력을 위한 위치를 구한다. */
    /* offset = (X의_위치 + Y의_위치 × 해상도의_넓이) × 색상의_바이트_수 */
        for(int x = start_x; x < end_x; x++){
			int offset = (x + y*vinfo.xres)*vinfo.bits_per_pixel/8.;
        	lseek(fd, offset, SEEK_SET);
        	write(fd, &b, 1);
        	write(fd, &g, 1);
        	write(fd, &r, 1);
        	write(fd, &a, 1);
        } 

//	drawpoint(fd, x, y, r, g, b);
}
#endif


#if 1
static void drawcircle(int fd, int center_x, int center_y, int radius, unsigned short color){
	int x = radius, y = 0;
	int radiusError = 1 - x;

	// 순환문을 이용해서 원 그리기: 정숫값을 계산해서 원 그리기
	while(x >= y){
		drawpoint(fd, x + center_x, y + center_y, color);
		drawpoint(fd, y + center_x, x + center_y, color);
		drawpoint(fd, -x + center_x, y + center_y, color);
		drawpoint(fd, -y + center_x, x + center_y, color);
		drawpoint(fd, -x + center_x, -y + center_y, color);
		drawpoint(fd, -y + center_x, -x + center_y, color);
		drawpoint(fd, x + center_x, -y + center_y, color);
		drawpoint(fd, y + center_x, -x + center_y, color);

		y++;
		if (radiusError < 0) {
			radiusError += 2 * y + 1;
		} else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}
#else
static void drawcircle(int fd, int center_x, int center_y, int radius, ubyte r, ubyte g, ubyte b){
	int x = radius, y = 0;
	int radiusError = 1 - x;

	// 순환문을 이용해서 원 그리기: 정숫값을 계산해서 원 그리기
	while(x >= y){
		drawpoint(fd, x + center_x, y + center_y, r, g, b);
		drawpoint(fd, y + center_x, x + center_y, r, g, b);
		drawpoint(fd, -x + center_x, y + center_y, r, g, b);
		drawpoint(fd, -y + center_x, x + center_y, r, g, b);
		drawpoint(fd, -x + center_x, -y + center_y, r, g, b);
		drawpoint(fd, -y + center_x, -x + center_y, r, g, b);
		drawpoint(fd, x + center_x, -y + center_y, r, g, b);
		drawpoint(fd, y + center_x, -x + center_y, r, g, b);

		y++;
		if (radiusError < 0) {
			radiusError += 2 * y + 1;
		} else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}
#endif

static void drawface(int fd, int start_x, int start_y, int end_x, int end_y, ubyte r, ubyte g, ubyte b){
	ubyte a = 0xFF;

	if(end_x == 0) end_x = vinfo.xres;
	if(end_y == 0) end_y = vinfo.yres;
	// 2 개의 for 루프를 이용해 면을 그림
	for(int x = start_x; x < end_x; x++){
		for(int y = start_y;y<end_y;y++){
			drawpoint(fd, x, y, makepixel(r,g,b));
			/*	
			int offset = (x + y*vinfo.xres)*vinfo.bits_per_pixel/8.;
			lseek(fd, offset, SEEK_SET);
			write(fd, &b, 1);
			write(fd, &g, 1);
			write(fd, &r, 1);
			write(fd, &a, 1);*/
		}
	}
}

// mmap() 함수를 이용해서 면을 그린다
static void drawfacemmap(int fd, int start_x, int start_y, int end_x, int end_y, \
	ubyte r, ubyte g, ubyte b){
	ubyte* pfb, a = 0xFF;
	int color = vinfo.bits_per_pixel/8.;

	if(end_x == 0) end_x = vinfo.xres;
	if(end_y == 0) end_y = vinfo.yres;

	// mmap() 함수를 이용해서 메모리맵을 작성한다
	pfb = (ubyte*)mmap(0, vinfo.xres * vinfo.yres * color, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	// 2개의 for 루프를 이용해서 면을 그린다
	for(int x = start_x; x < end_x*color; x+=color){
		for(int y = start_y; y < end_y; y++){
			*(pfb + (x+0) + y * vinfo.xres*color) = makepixel(r,g,b) / 3;
			*(pfb + (x+1) + y * vinfo.xres*color) = g;
			*(pfb + (x+2) + y * vinfo.xres*color) = r;
			*(pfb + (x+3) + y * vinfo.xres*color) = a;
		}	
	}

	// 사용이 끝난 메모리 메핑 해제
	munmap(pfb, vinfo.xres * vinfo.yres * color);
}

int main(int argc, char **argv)
{
    int fbfd, status, offset;

    fbfd = open(FBDEVICE, O_RDWR); 	/* 사용할 프레임 버퍼 디바이스를 연다. */
    if(fbfd < 0) {
        perror("Error: cannot open framebuffer device");
        return -1;
    }

    /* 현재 프레임 버퍼에 대한 화면 정보를 얻어온다. */
    if(ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) < 0) {
        perror("Error reading fixed information");
        return -1;
    }
#if 1
    
	//drawpoint(fbfd, 50, 50, 255, 0, 0); /* 빨간색(Red) 점을 출력 */
    //drawpoint(fbfd, 100, 100, 0, 255, 0); /* 초록색(Green) 점을 출력 */
    //drawpoint(fbfd, 150, 150, 0, 0, 255); /* 파란색(Blue) 점을 출력 */

	// 프랑스 국기 출력
	/*
	drawface(fbfd, 0, 0, vinfo.xres/3, 0, 0, 0, 255);
	drawface(fbfd, vinfo.xres/3, 0, vinfo.xres/3*2, 0, 255, 255, 255); 
	drawface(fbfd, vinfo.xres/3*2, 0, vinfo.xres, 0, 255, 0, 0); 
	*/
	//

	// 네덜란드 국기 출력
	/*
	drawface(fbfd, 0, 0, 0, vinfo.yres/3, 255, 0, 0);
	drawface(fbfd, 0, vinfo.yres/3, 0, vinfo.yres/3*2, 255, 255, 255); 
	drawface(fbfd, 0, vinfo.yres/3*2, 0, vinfo.yres, 0, 0, 255); 
	*/


	// 우크라이나 국기 출력
	/*	
	drawface(fbfd, 0, 0, 0, vinfo.yres/2, 0, 0, 255);
	drawface(fbfd, 0, vinfo.yres/2, 0, vinfo.yres, 255, 255, 0); 
	*/

	drawfacemmap(fbfd, 0, 0, vinfo.xres/3, 0, 0, 0, 255);
	drawfacemmap(fbfd, vinfo.xres/3, 0, vinfo.xres/3*2, 0, 255, 255, 255);
	drawfacemmap(fbfd, vinfo.xres/3*2, 0, vinfo.xres, 0, 255, 0, 0);
	// drawcircle(fbfd, 200, 200, 100, makepixel(255, 0, 255));


	//	drawcircle(fbfd, 200, 200, 100, 255, 0, 255); // magenta
	//  drawline(fbfd, 0, 100, 200, 0, 255, 255); // 청록색 생성

#else
	drawface(fbfd, 0, 0, 0, 0, 255, 255, 0); // 노란색 
	drawcircle(fbfd, 200, 200, 100, 255, 0, 255); // magenta
    drawline(fbfd, 0, 100, 200, 0, 255, 255); // 청록색 생성
#endif
    close(fbfd); 		/* 사용이 끝난 프레임 버퍼 디바이스를 닫는다. */

    return 0;
}
