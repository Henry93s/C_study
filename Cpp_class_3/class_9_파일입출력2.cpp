#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream ofs;

	// file.txt 파일을 연다(없으면 생성)
	ofs.open("test.txt");

	ofs.write("this is an apple", 16);

	// tellp() 맴버 함수를 이용해 파일의 현재 위치를 얻는다.
	long pos = ofs.tellp();
	cout << pos << endl; // thils is an apple 의 맨 끝 16

	ofs.close();
	return 0;
}