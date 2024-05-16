#include "DoQuiz.h"

/* 7 chapter */
void DoChapter(const std::wstring& chapter, std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz, float& grade) {

	/* Read file */
	short quantity = 0;
	std::vector<OOP> read_question;
	ReadFromFile(read_question, chapter, quantity);

	/* color_random: Random color */
	char color_random = 0, user_enter = 0, mark = 0;
	std::wstring check_empty, my_answer;
	std::wstring input_answer = L"\n\t----------------------------------\n\tNhập đáp án: ";

	/* start Counting how long */
	clock_t start_time = clock();

	short sleep_time;
	sleep_time = SleepTime(sleep_time);

	/* Do Chapter */
	for (short i = 0; i < quantity; i++) {

		system("cls");
		/* test print */
		SET_COLOR(lightyellow);
		std::wcout << L"\t---------------------------\n\t";
		std::wcout << L"Câu " << i + 1 << ": ";

		/* print question */
		PrintChangeColor(read_question[i].getQuestion());

		/* print answer */
		color_random = rand() % (15 - 9 + 1) + 9;
		SET_COLOR(color_random);
		std::wcout << L"\n\t";
		PrintFunny(read_question[i].getAnswer_a());

		color_random = rand() % (15 - 9 + 1) + 9;
		SET_COLOR(color_random);
		std::wcout << L"\n\t";
		PrintFunny(read_question[i].getAnswer_b());

		color_random = rand() % (15 - 9 + 1) + 9;
		SET_COLOR(color_random);
		std::wcout << L"\n\t";
		PrintFunny(read_question[i].getAnswer_c());

		color_random = rand() % (15 - 9 + 1) + 9;
		SET_COLOR(color_random);
		std::wcout << L"\n\t";
		PrintFunny(read_question[i].getAnswer_d());

		/* Reset color for line */
		SET_COLOR(lightwhite);
		PrintFunny(input_answer);


		/* input answer */
		do {

			std::getline(std::wcin, my_answer);

			/* stop doing test */
			if (my_answer == L"pt") {

				/* exit program */
				exit(EXIT_FAILURE);
			}

			CheckMyAnswer(my_answer, check_empty, user_enter);

		} while (my_answer == check_empty);

		/* if input answer is right or not */
		if (my_answer == read_question[i].getCheck_answer()) {

			/* blue for right answer */
			SET_COLOR(lightblue);
			std::wcout << L"\n\tĐáp án ĐÚNG, đáp án: \n";

			/* increase 1 for each right answer */
			mark++;
		}
		else {
			/* incorrect answer */
			incorrect_quiz.push_back({ i + 1, read_question[i], my_answer });

			/* red for wrong answer */
			SET_COLOR(lightred);

			std::wcout << L"\n\tĐáp án SAI, đáp án:\n";
		}

		/* read right answer */
		SET_COLOR(lightgreen);
		std::wcout << L"\t" << read_question[i].getAnswer() << "\n\n\n\t";

		if (sleep_time == 0) {
			SET_COLOR(black);
			system("pause");
		}
		else {
			std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
		}
		
	}

	/* stop counting */
	clock_t end_time = clock();

	/* duration of doing test */
	double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

	system("cls");
	SET_COLOR(lightblue);

	/* print grade for user */
	std::wcout << L"\n\n\n\t------------------------------------------\n\tBạn làm đúng " << (short)mark << L"/" << quantity << L" câu hỏi\n";
	grade = (float)mark * 10 / quantity;
	std::wcout << L"\tĐiểm của bạn là: " << std::setprecision(3) << grade << "\n\n";

	/* stressless*/
	SET_COLOR(lightyellow);
	FunnyGrade(grade);

	/* make fun of time*/
	SET_COLOR(lightaqua);
	ConvertTime(elapsed_time);
	FunnyTime(elapsed_time, quantity);
}

void AfterDoChapter(const float& grade, const std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz) {

	if (grade != 10) {
		std::wcout << L"\n\n\tTiếp tục xem đáp án bạn đã làm chưa đúng!\n\n\n\t";

		SET_COLOR(black);
		system("pause");
		system("cls");

		SET_COLOR(lightaqua);
		std::wcout << L"\n\n\tNhững câu bạn làm chưa đúng!\n\tXem lại coi có bị oan không nhé!\n\n\t";

		/* print incorrect answer */
		ReviewQuiz(incorrect_quiz);

		std::wcout << L"\n\n\t----------------------------------------------------------------------";
		std::wcout << L"\n\n\tCảm thấy làm bài như này có ổn không?!\n\n\n\t";
	}
	else {
		std::wcout << L"\n\n\t10 điểm về chỗ!\n\tLấy 10 điểm bài DoTest luôn nhé!\n\n\t";
	}

	SET_COLOR(black);
	system("pause");
	system("cls");
}


/* quiz */
void DoTest(const std::wstring& filename, std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz, float& grade,const short& choice) {

	/* Read file */
	short quantity = 0;
	std::vector<OOP> read_question;
	ReadFromFile(read_question, filename, quantity);

	/* n: Random color, count = stop when 60, quiz: random question */
	char count = 0, color_random = 0, enter = 0, mark = 0;
	short quiz = 0, sleep_time;
	sleep_time = SleepTime(sleep_time);

	std::set<short> st;
	std::wstring check_empty, my_answer, input_answer = L"\n\t----------------------------------\n\tNhập đáp án: ";

	/* start Counting time do quiz */
	clock_t start_time = clock();

	/* only 269 quiz */
	while (1) {
		system("cls");

		quiz = rand() % quantity;
		if (st.find(quiz) != st.end()) {
			continue;
		}

		st.insert(quiz);

		try {

			/* test print */
			SET_COLOR(lightyellow);
			std::wcout << L"\t---------------------------\n\t";
			std::wcout << L"Câu " << (short)++count << ": ";

			if (count > choice) {
				break;
			}

			/* print question */
			PrintChangeColor(read_question[quiz].getQuestion());

			/* print answer */
			color_random = rand() % (15 - 9 + 1) + 9;
			SET_COLOR(color_random);
			std::wcout << L"\n\t";
			PrintFunny(read_question[quiz].getAnswer_a());

			color_random = rand() % (15 - 9 + 1) + 9;
			SET_COLOR(color_random);
			std::wcout << L"\n\t";
			PrintFunny(read_question[quiz].getAnswer_b());

			color_random = rand() % (15 - 9 + 1) + 9;
			SET_COLOR(color_random);
			std::wcout << L"\n\t";
			PrintFunny(read_question[quiz].getAnswer_c());

			color_random = rand() % (15 - 9 + 1) + 9;
			SET_COLOR(color_random);
			std::wcout << L"\n\t";
			PrintFunny(read_question[quiz].getAnswer_d());

			/* Reset color for line */
			SET_COLOR(lightwhite);			
			PrintFunny(input_answer);

			/* input answer */
			do {

				std::getline(std::wcin, my_answer);

				/* stop doing test */
				if (my_answer == L"pt") {
					/* exit program */
					exit(EXIT_FAILURE);
				}
				CheckMyAnswer(my_answer, check_empty, enter);

			} while (my_answer == check_empty);

			/* if input answer is correct or not */
			if (my_answer == read_question[quiz].getCheck_answer()) {

				/* blue for right answer */
				SET_COLOR(lightblue);
				std::wcout << L"\n\tĐáp án ĐÚNG, đáp án: \n";

				/* increase 1 for each correct answer */
				mark++;
			}
			else {
				/* red for incorrect answer */
				incorrect_quiz.push_back({ count, read_question[quiz], my_answer });

				SET_COLOR(lightred);
				std::wcout << L"\n\tĐáp án SAI, đáp án:\n";
			}

			/* read correct answer */
			SET_COLOR(lightgreen);
			std::wcout << L"\t" << read_question[quiz].getAnswer() << "\n\n\n\t";
		}
		catch (std::exception e) {
			std::wcout << L"Lỗi: " << e.what() << std::endl;
		}
		
		if (sleep_time == 0) {
			SET_COLOR(black);
			system("pause");
		}
		else {
			std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
		}
	}

	/* stop counting */
	clock_t end_time = clock();

	/* duration of doing test */
	double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

	system("cls");
	SET_COLOR(lightyellow);
	std::wcout << L"\n\n\n\t------------------------------------------\n";
	ConvertTime(elapsed_time);

	grade = (float)mark * 10 / choice;
	std::wcout << L"\t------------------------------------------\n";
	std::wcout << L"\n\tĐiểm của bạn: " << grade << L"\n\n";

	SET_COLOR(lightaqua);
	FunnyGrade(grade);
}

void AfterDoTest(const float& grade, const std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz) {
	if (grade == 10) {
		SET_COLOR(lightpurple);
		std::wcout << L"\tPassword Heart Beat: WPJ\n\n";
	}
	else {
		std::wcout << L"\n\n\tTiếp tục xem đáp án sai!";
		SET_COLOR(black);
		system("pause");
		system("cls");
		std::wcout << L"\n\n\tNhững câu bạn làm sai!\n";
		ReviewQuiz(incorrect_quiz);
	}

	SET_COLOR(black);
	system("pause");
	system("cls");
}