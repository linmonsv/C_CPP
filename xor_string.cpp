#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	auto buf1 = "\x12\x34\x56\x78\x11\x22\x33\x44";
	auto buf2 = "\x11\x22\x33\x44\x55\x66\x77\x88";
	unsigned char res[8] = "\0";

	for(auto i = 0; i < 8; i ++)
	{
		res[i] = buf1[i] ^ buf2[i];
		cout << setw(2) << setfill('0') << hex << uppercase << (short)res[i] << endl;
	}

	return 0;
}
