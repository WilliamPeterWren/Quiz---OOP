#pragma once

#include "OOP.h"
#include "NotNeccessary.h"
#include "Read.h"
#include "Color.h"

/* decrypt file .txt */
std::wstring xorEncryptDecryptUserName(const std::wstring& input, const wchar_t key);

/* check input answer */
void CheckMyAnswer(std::wstring& my_answer, std::wstring& check_empty, char& enter);

/* review */
void ReviewQuiz(const std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz);

/* reduce stress */
void PrintFunny(const std::wstring& text_input);

/* sleep */
short SleepTime(short& sleep_time);