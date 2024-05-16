#include "Function.h"

/* decrypt file .txt */
std::wstring xorEncryptDecryptUserName(const std::wstring& input, const wchar_t key) {
	std::wstring result;

	int size = input.size();
	for (int i = 0; i < size; i++) {
		result += input[i] ^ key;
	}

	return result;
}

/* check input answer */
void CheckMyAnswer(std::wstring& my_answer, std::wstring& check_empty, char& enter) {

	/* reset check_empty */
	if (check_empty.size() > 0) {
		std::wstring temp;
		check_empty = temp;
	}

	/* stringstream */
	std::wstringstream ss(my_answer);
	while (ss >> check_empty) {
		my_answer = check_empty;
	}

	/* only if input 1 word */
	if (check_empty.size() == 1) {

		std::wstring temp;

		if (check_empty[0] == 'a' || check_empty[0] == 'b' || check_empty[0] == 'c' || check_empty[0] == 'd') {

			/* reset check_empty for next input */
			check_empty = temp;

			return;
		}

		/* check if input capitalize answer */
		switch (check_empty[0]) {
		case 'A':
			my_answer[0] = 'a';

			/* reset check_empty for next input */
			check_empty = temp;
			return;
		case 'B':
			my_answer[0] = 'b';

			/* reset check_empty for next input */
			check_empty = temp;
			return;
		case 'C':
			my_answer[0] = 'c';

			/* reset check_empty for next input */
			check_empty = temp;
			return;
		case 'D':
			my_answer[0] = 'd';

			/* reset check_empty for next input */
			check_empty = temp;
			return;
		}
	}

	/* input many word */
	if (check_empty.size() > 1) {
		std::wcout << L"\n\tNhập 1 đáp án a, b, c hoặc d thôi. Nhập gì nhiều thế!\n\tNhập lại đáp án coi: ";
		return;
	}

	/* not input answer */
	if (check_empty.size() == 0) {

		/* enter alot */
		if (enter > 0) {
			std::wcout << L"\n\tEnter hơi nhiều rồi đó! Có nhập đáp án không thì bảo!\n";
		}

		/* print */
		std::wcout << L"\n\tNhập đáp án đi... enter cái gì!\n\tNhập đáp án đi cho coi kết quả: ";
		enter++;
		return;
	}

	std::wcout << L"\n\tĐáp án của người ta chỉ có a, b, c hoặc d thôi. Nhập cái gì dạiiiii má? Nhập lại coi!\n\tNhập lại đáp án xem coi có nhập bậy nữa không: ";
}

/* reduce stress */
void PrintFunny(const std::wstring& text_input) {

	/* Use this code */
	for (int i = 0; i < text_input.size(); i++) {
		std::wcout << text_input[i];
		std::this_thread::sleep_for(std::chrono::microseconds(10));
	}

	/* Quick Test only */
	//std::wcout << text_input;
}

/* review */
void ReviewQuiz(const std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz) {

	char color_random = 0;
	std::wstring input_answer = L"\n\t---------------------------\n\tĐáp án của bạn: ";

	for (std::tuple<int, OOP, std::wstring> temp : incorrect_quiz) {
		/* Question number */
		SET_COLOR(lightyellow);
		std::wcout << L"\n\n\t---------------------------\n\t";
		std::wcout << L"Câu " << std::get<0>(temp) << ": ";

		/* print question */
		PrintChangeColor(std::get<1>(temp).getQuestion());

		/* print answer */
		color_random = rand() % (15 - 9 + 1) + 9;
		SET_COLOR(color_random);
		std::wcout << L"\n\t";
		PrintFunny(std::get<1>(temp).getAnswer_a());

		color_random = rand() % (15 - 9 + 1) + 9;
		SET_COLOR(color_random);
		std::wcout << L"\n\t";
		PrintFunny(std::get<1>(temp).getAnswer_b());

		color_random = rand() % (15 - 9 + 1) + 9;
		SET_COLOR(color_random);
		std::wcout << L"\n\t";
		PrintFunny(std::get<1>(temp).getAnswer_c());

		color_random = rand() % (15 - 9 + 1) + 9;
		SET_COLOR(color_random);
		std::wcout << L"\n\t";
		PrintFunny(std::get<1>(temp).getAnswer_d());

		/* Your answer */
		SET_COLOR(lightwhite);
		PrintFunny(input_answer);
		std::wcout << std::get<2>(temp) << "\n\t";

		/* Right answer */
		SET_COLOR(lightyellow);
		std::wcout << L"Đáp án đúng: " << std::get<1>(temp).getAnswer();

	}
	std::wcout << L"\n\n\n\t";

}

/* sleep */
short SleepTime(short& sleep_time) {
	std::wstring temp, enter = L"\n\n\n\t";

	const std::wstring input = L"Thời gian chờ giữa các câu hỏi.\n\tBỏ trống dừng vô thời hạn - tối đa 60 giây.\n\n\tThích chờ bao lâu vậy mé: ";
	const std::wstring input_charater = L"Nhập số thôi má! Nhập lại!";
	const std::wstring input_negative = L"Thời gian chờ mà âm hả má! Nhập lại!";
	const std::wstring input_maximum = L"Đã nói là tối đa 60 giây mà?!\n\tMuốn lâu hơn thì bỏ trống đi! Nhập lại!";

	do {
		system("cls");
		sleep_time = 0;
		SET_COLOR(lightyellow);

		try {
			PrintFunny(enter);
			PrintFunny(input);
			
			SET_COLOR(lightaqua);
			std::getline(std::wcin, temp);

			if (temp == L"") {
				return sleep_time;
			}

			sleep_time = std::stoi(temp);		
		}
		catch (std::exception e) {
			PrintFunny(enter);
			PrintFunny(input_charater);			
			PrintFunny(enter);
			sleep_time = 0;

			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		}

		if (sleep_time < 0) {
			PrintFunny(enter);
			PrintFunny(input_negative);		
			PrintFunny(enter);

			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		}

		if (sleep_time > 60) {
			PrintFunny(enter);
			PrintFunny(input_maximum);
			PrintFunny(enter);

			std::this_thread::sleep_for(std::chrono::seconds(3));
			continue;
		}


	} while (sleep_time <= 0 || sleep_time > 60);

	return sleep_time;
}