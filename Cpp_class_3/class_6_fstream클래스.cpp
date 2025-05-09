#include <iostream>
#include <fstream> // #include fstream
#include <string>
using namespace std;

int main() {
	fstream fs;

	// 파일에 출력
	fs.open("test.txt", ios::out);
	if (fs.fail()) { // file 열기 실패 시 true 반환
		return 0;
	}

	fs << "keyboard" << endl;
	fs << "monitor" << endl;

	fs.close();

	// ios::trunc : 기존에 파일이 있을 경우 삭제하고 새로운 파일을 생성하여 출력
	fs.open("test.txt", ios::out | ios::trunc);
	fs << "desk" << endl;
	fs.close();

	// 파일에서 읽어오기
	fs.open("test.txt", ios::in);
	string temp;

	while (fs >> temp, !fs.eof()) {
		cout << temp << endl;
	}

	fs.close();
}