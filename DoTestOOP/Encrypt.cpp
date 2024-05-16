#include "Encrypt.h"

/* encrypt decrypt */
void xorEncryptDecrypt(const std::wstring& inputFileName, const std::wstring& outputFileName, const wchar_t& key) {

	/* read input file */
	std::wifstream inputFile(inputFileName, std::ios::binary);

	/* write output file */
	std::wofstream outputFile(outputFileName, std::ios::binary);
	wchar_t ch;

	// xor
	while (inputFile.get(ch)) {
		ch = ch ^ key;
		outputFile.put(ch);
	}

	inputFile.close();
	outputFile.close();
}
