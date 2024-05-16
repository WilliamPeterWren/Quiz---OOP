#include "Read.h"

/* read data: 7 chapter + 2 quiz */
void ReadFromFile(std::vector<OOP>& read_question, const std::wstring& filename, short& quantity) {

	/* Read file temp.txt */
	std::wifstream fin(filename);

	/* can't read file */
	if (!fin) {
		std::wstring file_delete = L"\n\n\tXóa file của người ta hay gì?!\n\tTìm không có thấy file má ơiiii!\n\n\tChạy lại chương trình nha!\n\n\n";
		PrintFunny(file_delete);
		
		std::this_thread::sleep_for(std::chrono::seconds(4));
		exit(EXIT_FAILURE);
	}

	/* locale: read file unicode */
	std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
	fin.imbue(loc);

	fin >> quantity;
	std::wstring file_change = L"\n\n\tAi cho sửa file của người ta dị?!\n\n\tGiờ mà không sửa lại file cũ là khỏi làm bài nha má!\n\n\tHư quá mà!\n\n\n\t";
	if (quantity < 9 || quantity > 404) {			
		PrintFunny(file_change);
		 
		std::this_thread::sleep_for(std::chrono::seconds(4));
		exit(EXIT_FAILURE);
	}

	/* Question oop */
	read_question.resize(quantity);

	/* last_word: stop read question */
	std::wstring last_word = L"Đáp án:", temp;

	/* read from file */
	for (int i = 0; i < quantity; i++) {
		std::wstring tmp;

		do {

			std::getline(fin, tmp);

			if (tmp == last_word) {
				temp += L" williammikiejames " + tmp + L" williammikiejames ";
			}
			else {
				temp += tmp + L" williammikiejames ";
			}

		} while (tmp != last_word);

		read_question[i].setQuestion(temp);

		/* Get Answer A */
		std::getline(fin, temp);
		read_question[i].setAnswer_a(temp);
		if (toupper(read_question[i].getAnswer_a()[0]) != L'A' || temp.size() < 4) {
			PrintFunny(file_change);

			std::this_thread::sleep_for(std::chrono::seconds(4)); 
			exit(EXIT_FAILURE);
		}

		/* Get Answer B */
		std::getline(fin, temp);
		read_question[i].setAnswer_b(temp);
		if (toupper(read_question[i].getAnswer_b()[0]) != L'B' || temp.size() < 4) {
			PrintFunny(file_change);

			std::this_thread::sleep_for(std::chrono::seconds(4)); 
			exit(EXIT_FAILURE);
		}

		/* Get Answer C */
		std::getline(fin, temp);
		read_question[i].setAnswer_c(temp);
		/* error chương 7 câu C. Array */
		/*if (read_question[i].getAnswer_c()[0] != L'C' || temp.size() < 4) {
			PrintFunny(file_change);

			std::this_thread::sleep_for(std::chrono::seconds(4)); 
			exit(EXIT_FAILURE);
		}*/		

		/* Get Answer D */
		std::getline(fin, temp);
		read_question[i].setAnswer_d(temp);
		if (toupper(read_question[i].getAnswer_d()[0]) != L'D' || temp.size() < 4) {
			PrintFunny(file_change);

			std::this_thread::sleep_for(std::chrono::seconds(4)); 
			exit(EXIT_FAILURE);
		}
		
		/* Right Answer */
		std::getline(fin, temp);
		read_question[i].setCheck_answer(temp);
		if (temp.size() > 1) {
			PrintFunny(file_change);

			std::this_thread::sleep_for(std::chrono::seconds(4)); 
			exit(EXIT_FAILURE);
		}

		/* Answer data */
		std::getline(fin, temp);
		read_question[i].setAnswer(temp);
		if (temp.size() < 2) {			
			PrintFunny(file_change);

			std::this_thread::sleep_for(std::chrono::seconds(4)); 
			exit(EXIT_FAILURE);
		}


		temp = L"";
	}
	fin.close();

	/* delete data in temp and quiz */
	std::wofstream outputFileTemp("temp.txt", std::ofstream::out | std::ofstream::trunc);
}