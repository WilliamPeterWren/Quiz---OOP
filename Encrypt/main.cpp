#include <iostream>
#include <io.h> //set_mode()
#include <fcntl.h> //_O_WTEXT
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// read file
void xorEncryptDecrypt(wstring inputFileName, wstring outputFileName, wchar_t key) {

	wifstream inputFile(inputFileName, ios::binary);
	wofstream outputFile(outputFileName, ios::binary);

	wchar_t ch;
	while (inputFile.get(ch)) {
		ch = ch ^ key;
		outputFile.put(ch);
	}
	inputFile.close();
	outputFile.close();
	std::wcout << "Successfull!\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);	

	wstring filename, readfile;

	std::wcout << L"Nhập file in: ";
	getline(std::wcin, filename);

	std::wcout << L"Nhập file out: ";
	getline(std::wcin, readfile);


	wchar_t key = L'A'; // You can choose any key	

	xorEncryptDecrypt(filename, readfile, key);


	return 0;
}