#include <iostream>
#include <fstream> // #include fstream
#include <string>
using namespace std;

int main() {
	string str = "testinput";

	// output stream
	ofstream output; 
	output.open("test.txt"); // == ofstream ofs("test.txt");

	output << str;
	output.close();

	// input stream
	ifstream ifs("test.txt"); // == ifstream input; input.open("test.txt");

	ifs >> str;
	cout << str << endl;
	ifs.close();
}