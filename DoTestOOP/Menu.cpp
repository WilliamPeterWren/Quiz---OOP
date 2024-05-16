#include "Menu.h"

short menu() {

	system("cls");

	/* Lấy thời gian hiện tại */
	std::time_t now = std::time(nullptr);

	/* Chuyển đổi thời gian thành struct std::tm */
	std::tm* localTime = std::localtime(&now);
	std::wstringstream wss;

	/* get day */
	int currentDay = localTime->tm_mday;
	wss << currentDay;
	std::wstring day = wss.str();
	wss.str(L"");

	/* get month */
	int currentMonth = localTime->tm_mon + 1; /* Tháng từ 0 đến 11 */
	std::wstring month;
	switch (currentMonth)
	{
	case 1:
		month = L"January";
		break;
	case 2:
		month = L"February";
		break;
	case 3:
		month = L"March";
		break;
	case 4:
		month = L"April";
		break;
	case 5:
		month = L"May";
		break;
	case 6:
		month = L"June";
		break;
	case 7:
		month = L"July";
		break;
	case 8:
		month = L"August";
		break;
	case 9:
		month = L"September";
		break;
	case 10:
		month = L"October";
		break;
	case 11:
		month = L"November";
		break;
	case 12:
		month = L"December";
		break;
	default:
		month = L"Invalid Month";
		break;
	}

	/* get year */
	int currentYear = localTime->tm_year + 1900; /* Năm tính từ 1900 */
	wss << currentYear;
	std::wstring year = wss.str();
	wss.str(L"");


	/* get hour */
	int currentHour = localTime->tm_hour;
	wss << currentHour;
	std::wstring hour = wss.str();
	wss.str(L"");

	/* get minute */
	int currentMinute = localTime->tm_min;
	wss << currentMinute;
	std::wstring minute = wss.str();
	wss.str(L"");

	/* get second */
	int currentSecond = localTime->tm_sec;
	wss << currentSecond;
	std::wstring second = wss.str();
	wss.str(L"");	


	/* info */	
	const std::wstring line = L"\t-------------------------------------\n";
	const std::wstring author = L"\tÔn tập OOP lớp thầy Tú.\n";
	const std::wstring classid = L"\tProject nhỏ sinh viên năm nhất.\n\n";
	const std::wstring present = L"\tHiện tại : " + hour + L" giờ - " + minute + L" phút - " + second + L" giây\n";
	const std::wstring today =  L"\tHôm nay  : " + day + L" - " + month + L" - " + year + L"\n";
	const std::wstring goodluck = L"\tChúc các bạn 10 điểm.\n\n";
	const std::wstring chapter01 = L"\t\t01.  C++  1 - 9  câu\n";
	const std::wstring chapter02 = L"\t\t02.  C++  2 - 86 câu\n";
	const std::wstring chapter03 = L"\t\t03.  C++  3 - 29 câu\n";
	const std::wstring chapter04 = L"\t\t04.  C++  4 - 82 câu\n";
	const std::wstring chapter05 = L"\t\t05.  C++  5 - 30 câu\n";
	const std::wstring chapter06 = L"\t\t06.  C#   6 - 87 câu\n";
	const std::wstring chapter07 = L"\t\t07.  Java 7 - 80 câu\n\n";
	const std::wstring dotest60 = L"\t\t08.  DoTest - 60 câu\n";
	const std::wstring dotestoption = L"\t\t09.  DoTest - ?? câu\n\n";
	const std::wstring returnmenu = L"\t\t0. Return\n";
	const std::wstring input = L"\tChọn chương nào thì nhập cho đúng nha\n\tNhập sai thử là biết liền : ";

	std::wcout << L"\n\n";
	SET_COLOR(aqua);
	PrintFunny(line);

	SET_COLOR(lightyellow);
	PrintFunny(author);	
	PrintFunny(classid);

	SET_COLOR(lightaqua);
	PrintFunny(line);
	PrintFunny(present);
	PrintFunny(today);

	/* good luck */
	SET_COLOR(aqua);
	PrintFunny(line);
	PrintFunny(goodluck);
	PrintFunny(line);

	/* chapter choice */
	SET_COLOR(lightyellow);
	PrintFunny(chapter01);
	PrintFunny(chapter02);
	PrintFunny(chapter03);
	PrintFunny(chapter04);
	PrintFunny(chapter05);
	PrintFunny(chapter06);
	PrintFunny(chapter07);

	/* quiz choice */
	SET_COLOR(lightaqua);

	PrintFunny(dotest60);
	PrintFunny(dotestoption);

	/* return */
	SET_COLOR(lightred);
	PrintFunny(returnmenu);

	/* line */
	SET_COLOR(lightyellow);
	PrintFunny(line);
	PrintFunny(input);


	int option = 0;
	int count_negative = 0, count_positive = 0;

	std::wstring temp;
	
	/* check input before doing test */
	do {
		std::getline(std::wcin, temp);

		option = CheckInput(temp, count_negative, count_positive);

	} while (option < 0 || option > 9);

	return option;
}

short updateChoice() {
	short choice = 0;

	const std::wstring input = L"Nhập số lượng câu hỏi muốn thử sức: ";
	const std::wstring input_character = L"Nhập số bà nội ơi! Nhập cái gì dị má?";
	const std::wstring input_negative = L"Số lượng mà âm thì làm bài kiểu gì hẻ mé?!\n\n\tNhập lại nha mắm!";
	const std::wstring input_minimum = L"Nhát dị má?! Dưới 30 câu không cho làm!\n\n\tCan đảm lên nào công chúa bong bóng!";
	const std::wstring input_maximum = L"Cả đề có 404 câu hỏi thui!\n\n\tCan đảm quá thì lên gặp thầy Tú xin thêm đề!";
	
	do {
		system("cls");
		SET_COLOR(lightyellow);
		std::wstring temp;
		std::wstring enter = L"\n\n\n\t";
		PrintFunny(enter);

		try {			
			PrintFunny(input);
			std::getline(std::wcin, temp);
			choice = std::stoi(temp);
		}
		catch (std::exception e) {
			PrintFunny(enter);
			PrintFunny(input_character);
			PrintFunny(enter);

			std::this_thread::sleep_for(std::chrono::seconds(2));									
			continue;
		}

		if (choice < 0) {
			PrintFunny(enter);
			PrintFunny(input_negative);
			PrintFunny(enter);

			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		}

		if (choice < 30) {
			PrintFunny(enter);
			PrintFunny(input_minimum);
			PrintFunny(enter);
						
			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		}

		if (choice > 404) {
			PrintFunny(enter);
			PrintFunny(input_maximum);
			PrintFunny(enter);
			
			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		}
			
	} while (choice < 30 || choice > 404);
	

	return choice;
}