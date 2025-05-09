#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	fstream fp;
	int data, score[5] = { 78,96,100,25,96 };

	// write
	fp.open("test.txt", ios::out | ios::binary); // 출력 이진파일 설정
	fp.write((char*)score, 20); // score 위치에서 20 바이트 출력
	fp.close();


	// read
	fp.open("test.txt", ios::in | ios::binary);
	if (fp.fail()) {
		return 1;
	}
	fp.read((char*)&data, 4);
	cout << setw(3) << right << data << endl; // 출력폭 3 크기 78 출력

	fp.seekg(4, ios::cur); // 파일에 "입력" 할 때 파일 포인터 이동(get)
	fp.read((char*)&data, 4);
	cout << setw(3) << right << data << endl; // 출력폭 3 크기 100 출력
	fp.close();

	return 0;
}