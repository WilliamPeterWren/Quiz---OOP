#pragma once

#include "OOP.h"


/* answer_sheet_chuongxx.txt */
void WriteAnswerSheet(const std::wstring& chapter, const std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz);

/* chuongxx_grade.txt */
void WriteGrade(const std::wstring& chapter, const float& grade);