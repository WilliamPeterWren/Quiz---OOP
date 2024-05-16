#include "Write.h"

/* answer_sheet_chuongxx.txt */
void WriteAnswerSheet(const std::wstring& chapter, const std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz) {

	std::wstring answer_sheet = L"answer_sheet_chuong01.txt";
	answer_sheet[20] = chapter[7];

	/* write file for seen later */
	std::wofstream fout(answer_sheet);

	/* can't create file */
	if (!fout.is_open()) {
		std::wcout << L"Không tạo được file " << answer_sheet << "\n";
		exit(EXIT_FAILURE);
	}

	/* write file answer_sheet */
	int n = incorrect_quiz.size();
	for (int i = 0; i < n; i++) {
		fout << std::get<0>(incorrect_quiz[i]) << L": " << std::get<2>(incorrect_quiz[i]) << " - False\n";
	}


	fout.close();
}

/* chuongxx_grade.txt */
void WriteGrade(const std::wstring& chapter, const float& grade) {

	std::wstring tenFile = L"score.txt";

	std::wofstream file(tenFile, std::ios::app);

	// Kiểm tra xem file có mở thành công hay không
	if (!file.is_open()) {
		exit(EXIT_FAILURE);
	}

	if (chapter != L"quizen.txt") {
		file << L"chuong 0" << chapter[7] << L" - diem: " << std::setprecision(2) << grade << "\n";
	}
	else {
		file << "quiz 60 cau" << chapter[7] << " - diem: " << std::setprecision(2) << grade << "\n";
	}


	file.close();
}