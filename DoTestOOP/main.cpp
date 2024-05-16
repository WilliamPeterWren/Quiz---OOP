#include "Function.h"
#include "NotNeccessary.h"
#include "Encrypt.h"
#include "Color.h"
#include "Menu.h"
#include "DoQuiz.h"
#include "Write.h"

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);

	srand((unsigned int)time(NULL));

	std::wstring chapter = L"chuong01en.txt", quiz = L"quizAen.txt", temp = L"temp.txt";

	/* incorrect answer in Quiz */
	std::vector<std::tuple<short, OOP, std::wstring>> incorrect_quiz;

	float grade = 0;

	/* You can choose any key */
	wchar_t key = L'A';

	UserName();
	PrintHacked();
	Reconnect();

	short option = 0, choice = 60;
	while (!option) {

		option = menu();

		switch (option) {
		case 0:
			return EXIT_SUCCESS;

		case 1:		
			chapter[7] = '1';
			break;

		case 2:			
			chapter[7] = '2';
			break;

		case 3:		
			chapter[7] = '3';
			break;

		case 4:			
			chapter[7] = '4';
			break;

		case 5:
			chapter[7] = '5';
			break;

		case 6:
			chapter[7] = '6';
			break;

		case 7:
			chapter[7] = '7';
			break;

		case 8:
			quiz[4] = 'A';
			break;

		case 9:
			quiz[4] = 'B';
			choice = updateChoice();
			break;
		}	

		if (option >= 8) {

			/* encrypt file Quiz */
			xorEncryptDecrypt(quiz, temp, key);

			/* Do test*/
			DoTest(temp, incorrect_quiz, grade, choice);

			WriteGrade(quiz, grade);

			AfterDoTest(grade, incorrect_quiz);
		}
		else {

			/* encrypt file 7 Chapter */ 
			xorEncryptDecrypt(chapter, temp, key);

			/* read file */
			DoChapter(temp, incorrect_quiz, grade);
			
			/* write file after Do chapter */
			WriteAnswerSheet(chapter, incorrect_quiz);
			WriteGrade(chapter, grade);

			AfterDoChapter(grade, incorrect_quiz);
		}	

		// refresh		
		system("cls");

		SET_COLOR(lightaqua);
		std::wcout << L"\n\n\t---------- Làm xong rồi chứ gì ----------\n\n";
		
		SET_COLOR(lightyellow);
		std::wcout << L"\tLàm lại đề khác: Bấm cái gì cũng được!\n";
		std::wcout << L"\tThôi dẹp nghỉ khỏe không làm nữa: bấm Enter!\n";
		std::wcout << L"\tSuy nghĩ kỹ coi nên chọn cái gì: ";
		
		SET_COLOR(lightwhite);
		
		/* Exit DoTest */
		std::wstring input;
		std::getline(std::wcin, input);

		if (input == L"") {
			exit(EXIT_FAILURE);
		}
		else {
			option = 0;
		}
	}
			
	return EXIT_SUCCESS;
}