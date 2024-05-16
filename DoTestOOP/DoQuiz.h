#pragma once


#include "OOP.h"
#include "Function.h"


/* 7 chapter */
void DoChapter(const std::wstring& chapter, std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz, float& grade);

void AfterDoChapter(const float& grade, const std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz);


/* quiz */
void DoTest(const std::wstring& quiz, std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz, float& grade,const short& choice);

void AfterDoTest(const float& grade, const std::vector<std::tuple<short, OOP, std::wstring>>& incorrect_quiz);