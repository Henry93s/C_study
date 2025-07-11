#include <stdio.h>

#include "bmpHeader.h"

int readBmp(char* filename, unsigned char** data, int* cols, int* rows){
	BITMAPFILEHEADER bmpHeader;
	BITMAPINFOHEADER bmpInfoHeader;
	FILE* fp;

	// bmp file open
	fp = fopen(filename, "rb");
	if(fp == NULL){
		perror("ERROR\n");
		return -1;
	}

	// BITMAPFILEHEADER 구조체 데이터
	fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, fp);

	// BITMAPINFOHEADER 구조체 데이터
	fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

	// 트루 컬러를 지원하지 않으면 표시할 수 없음
	if(bmpInfoHeader.biBitCount != 24){
		perror("This image ifle doesn't supports 24bit color\n");
		fclose(fp);
		return -1;
	}

	// 해상도 정보 가져옴
	*cols = bmpInfoHeader.biWidth;
	*rows = bmpInfoHeader.biHeight;
	//*color = bmpInfoHeader.biBitCount;

	// 이미지 해상도(넓이 * 깊이)
	printf("Resolution : %d x %d\n", bmpInfoHeader.biWidth, bmpInfoHeader.biHeight);
	printf("Bit Count : %d\n", bmpInfoHeader.biBitCount); // 픽셀당 비트 수(색상)

	// 실제 이미지 데이터가 있는 위치를 계산해서 가져옴
	fseek(fp, bmpHeader.bfOffBits, SEEK_SET);
	fread(*data, 1, bmpHeader.bfSize-bmpHeader.bfOffBits, fp);

	fclose(fp); // 이미지 파일 사용 끝남

	return 0;
}
