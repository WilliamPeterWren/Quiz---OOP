#include "NotNeccessary.h"


void UserName() {

	std::wstring username;

	// Tên file cần kiểm tra
	std::wstring tenFile = L"tmp.txt";

	// Mở file để đọc
	std::wifstream file(tenFile);

	// Kiểm tra xem file có mở thành công hay không
	const std::wstring enter = L"\n\n\n\t";
	const std::wstring username_deleted = L"Xóa mất file của người ta rồi còn đâu!";
	const std::wstring username_return = L"Trả lại file mới làm được bài!";

	if (!file.is_open()) {

		SET_COLOR(lightred);
		PrintFunny(enter);
		PrintFunny(username_deleted);

		SET_COLOR(lightyellow);
		PrintFunny(enter);
		PrintFunny(username_return);
		PrintFunny(enter);

		std::this_thread::sleep_for(std::chrono::seconds(2));
		exit(EXIT_FAILURE);
	}

	
	const std::wstring first_time = L"Lần đầu đặt chân trái đến đây đúng khum?!";
	const std::wstring question = L"Quần đảo Hoàng Sa và Trường Sa của nước nào?" + enter + L"Trả lời : ";
	const std::wstring right_answer = L"Tốt! 10 điểm!" + enter + L"Create username: ";
	const std::wstring study = L"Học bài tiếp hẻ? Siêng dị ";
	const std::wstring hidden = L"Ẩn file username.txt của người ta chi vậy cha nội?!" + enter + L"Bật file lại mới làm bài được";
	const std::wstring vietnam = L"Không phải con rồng cháu tiên không cho làm bài!";
	const std::wstring username_length = L"Nhập vừa phải thôi" + enter + L"Tên gì mà dài thế ? !" + enter + L"Nhập lại nào: ";


	// Kiểm tra xem file có rỗng hay không
	if (file.peek() == std::wifstream::traits_type::eof()) {

		PrintWilliam();
		system("cls");

		SET_COLOR(lightyellow);
		PrintFunny(enter);
		PrintFunny(first_time);		

		SET_COLOR(lightgreen);
		PrintFunny(enter);
		PrintFunny(question);		

		SET_COLOR(lightaqua);
		std::getline(std::wcin, username);

		std::wstringstream wss(username);
		std::wstring temp, answer;
		while (wss >> temp) {
			answer += temp;
		}

		if (answer != L"ViệtNam") {
			PrintFunny(enter);
			PrintFunny(vietnam);
			PrintFunny(enter);

			std::this_thread::sleep_for(std::chrono::seconds(4));
			exit(EXIT_FAILURE);
		}

		SET_COLOR(lightyellow);
		PrintFunny(enter);
		PrintFunny(right_answer);

		do {
			SET_COLOR(lightaqua);
			std::getline(std::wcin, username);

			if (username.length() > 50) {
				PrintFunny(enter);
				PrintFunny(username_length);
				std::wcin.ignore();
			}

		} while (username.length() > 50);
		

		wchar_t key = L'A';
		temp = xorEncryptDecryptUserName(username, key);

		std::wofstream username_out(tenFile);

		/* can't create file */
		if (!username_out.is_open()) {
			PrintFunny(enter);
			PrintFunny(hidden);

			std::this_thread::sleep_for(std::chrono::seconds(4));
			exit(EXIT_FAILURE);
		}

		/* write username to file username.txt */
		username_out << temp;

		username_out.close();
	}
	else {

		wchar_t key = L'A';
		
		std::wstring temp;
		std::getline(file, temp);
		
		username = temp;
		username = xorEncryptDecryptUserName(username, key);

		SET_COLOR(lightaqua);
		PrintFunny(enter);
		PrintFunny(study);

		/* read username from file username.txt */
		SET_COLOR(lightyellow);
		std::wcout<< username << std::endl;
	}

	file.close();
}

void PrintWilliam() {

	std::wstring temp = L"\n\n\tCũng là in ra màn hình nhưng mà nó lạ lắm:\n\n\t\t";

	SET_COLOR(lightblue);
	for (int i = 0; i < temp.size(); i++) {
		std::wcout << temp[i];
		std::this_thread::sleep_for(std::chrono::microseconds(20000));
	}

	SET_COLOR(lightyellow);
	std::wstring william = L"Peter William Wren";
	int n = 0, i = 0;

	do {

		do {
			n = rand() % (64 - 32 + 1) + 32;
			if (n == 32) {
				break;
			}

			n = rand() % (122 - 65 + 1) + 65;

		} while (n > 90 && n < 97);

		std::wcout << char(n);

		if ((int)william[i] != n) {
			std::wcout << L"\b";
			std::this_thread::sleep_for(std::chrono::microseconds(100));
		}
		else {
			i++;
		}

		if (i >= william.size()) {
			break;
		}
	} while (1);

	std::this_thread::sleep_for(std::chrono::seconds(2));
}

void PrintHacked() {

	const std::wstring enter = L"\n\n\n\t";
	const std::wstring warning = L"Warning!";
	const std::wstring hacked = L"Hacked: ";

	std::this_thread::sleep_for(std::chrono::microseconds(500000));

	SET_COLOR(yellow);
	PrintFunny(enter);
	PrintFunny(warning);

	std::this_thread::sleep_for(std::chrono::seconds(1));

	SET_COLOR(lightred);
	PrintFunny(enter);
	PrintFunny(hacked);

	for (int i = 0; i <= 100; i++) {
		if (i < 10) {
			std::wcout << L"0" << i << L"%";
		}
		else {
			std::wcout << i << L"%";
		}

		std::this_thread::sleep_for(std::chrono::microseconds(800));
		std::wcout << L"\b\b\b";
	}
}

void Reconnect() {

	SET_COLOR(gray);
	std::wstring temp = L"Back to menu... ";
	std::wcout << L"\n\n\n\t";

	for (int i = 0; i < temp.size(); i++) {
		std::wcout << temp[i];
		std::this_thread::sleep_for(std::chrono::microseconds(20000));
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void ConvertTime(double& real_time) {

	long long temp = real_time;
	double hour = 0, minute = 0;


	/* get hour */
	hour = temp / 3600;

	/* second left */
	temp = temp % 3600;

	/* get minute */
	minute = temp / 60;

	/* second left */
	temp %= 60;

	/* print */
	std::wcout << L"\tThời gian làm bài: ";

	/* print hour */
	if (hour > 0) {
		std::wcout << hour << L" giờ ";
	}

	/* print minute */
	if (minute > 0) {
		std::wcout << minute << L" phút ";
	}

	/* print second */
	std::wcout << temp << L" giây\n";
}

void FunnyTime(const short& real_time, short quantity) {
	std::wcout << L"\n\t------------------------------------------\n";
	std::wcout << L"\t";

	if (real_time > 3600) {
		std::wcout << L"Làm lâu dữ dị bà nội!\n";
	}
	else if (real_time > 2700) {
		std::wcout << L"Làm bài cũng lâu hen!\n";
	}
	else if (real_time > 1800) {
		std::wcout << L"Thời gian làm bài tạm chấp nhận được thôi nha!\n";
	}
	else if (real_time > 1200) {
		std::wcout << L"Thời gian làm bài hợp lý đó: từ 20 đến 30 phút là hợp lý!\n";
	}
	else if (real_time > 600) {
		std::wcout << L"Cái gì mà hơn 10 phút đã làm xong rồi!\n";
	}
	else if (real_time > 300) {
		std::wcout << L"Làm bài chưa tới 10 phút luôn!\n\tLàm thật không hay chọn bừa đó?!\n";
	}
	else {
		std::wcout << L"Cái này là học thuộc đáp án nè!\n\tLàm bài chưa tới 5 phút nữa!\n\tKhông thể chấp nhận được mà!\n";
	}

	if (quantity == 30) {
		std::wcout << L"\tThấy chương này thế nào? Có 30 câu cưỡi ngựa xem hoa à!\n";
	}
}

void FunnyGrade(const float& grade) {
	std::wcout << L"\t------------------------------------------\n";
	std::wcout << L"\t";

	if (grade == 10) {
		std::wcout << L"Qua môn chắc kèo!\n";
	}
	else if (grade > 9) {
		std::wcout << L"Xuất cmn sắc luôn!\n";
	}
	else if (grade > 8) {
		std::wcout << L"Cũng giỏi đấy!\n";
	}
	else if (grade > 6.5) {
		std::wcout << L"Khá lắm!\n";
	}
	else if (grade > 5) {
		std::wcout << L"Tạm được thôi!\n";
	}
	else {
		std::wcout << L"Rớt môn! Sao mà cứu được nữa!\n";
	}
	std::wcout << L"\t------------------------------------------\n";
}

int CheckInput(const std::wstring& temp, int& count_negative, int& count_positive) {

	/* option print */
	const std::wstring enter = L"\n\n\t";
	const std::wstring input_character = enter + L"Nhập số thôi! Ai mượn nhập chữ chi dậy!" + enter + L"Có thấy người ta để lựa chọn là số không trời ?!" + enter + L"Nhập lại xem coi : ";
	const std::wstring input_sixgrade = enter + L"Lấy quyển toán lớp 6 ra học lại liền! Đã nói là nhập số LỚN HƠN 0 cơ mà!";
	const std::wstring negative_option = enter + L"Lúc thì nhập số âm, lúc thì nhập số ngoài option!" + enter + L"Bà nội muốn con sống sao ?!";
	const std::wstring negative_option2 = enter + L"Lày nhá! Hết nhập số lớn quá giờ lại nhập số âm cho nhiều lần nữa!" + enter + L"Biết hết đó đừng có đùa!" + enter + L"Chấp niệm cái sự cố chấp này quá à!";
	const std::wstring negative = enter + L"Thấy số không? Số 0 là nhỏ nhất rồi!" + enter + L"Nhập lại coi đã biết đếm số chưa!" + enter + L"Nhập lại nào : ";
	const std::wstring input_max = enter + L"Sao mà cố chấp quá dị! Đã nói là số lớn nhất là số 9 gòi mà!";
	const std::wstring chapter_quiz = enter + L"Nè người ta có 7 chương và 2 bài Quiz à? Nhập số gì dạiii trời!" + enter + L"Nhập lại coi nào : ";
	
	std::wstringstream ss(temp);
	std::wstring container;

	/* user input option */
	int option = 0;

	while (ss >> container) {
		try {
			option = stod(container);

			/* if option is ok */
			if (option >= 0 && option <= 9) {
				return option;
			}
		}
		catch (std::exception e) {

			/* catch if not input number */
			PrintFunny(input_character);
			return -1;
		}
	}

	/* input negative number */
	if (option < 0) {
		count_negative++;
		if (count_negative > 1) {

			/* input negative number */
			PrintFunny(input_sixgrade);

			/* input bigger number */
			if (count_positive > 0) {
				PrintFunny(negative_option);
				PrintFunny(negative_option2);
			}
		}

		/* negative */
		PrintFunny(negative);
	}

	/* input bigger number */
	if (option > 9) {
		count_positive++;
		if (count_positive > 1) {

			/* print: input bigger number many times */
			PrintFunny(input_max);

			/* print: input wrong number many times */
			if (count_negative > 0) {
				PrintFunny(negative_option);
				PrintFunny(negative_option2);
			}
		}

		/* bigger */
		PrintFunny(chapter_quiz);
	}

	return -1;
}