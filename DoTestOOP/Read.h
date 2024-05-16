#pragma once
#include "OOP.h"
#include "Color.h"

/* read data: 7 chapter + 2 quiz */
void ReadFromFile(std::vector<OOP>& read_question, const std::wstring& filename, short& quantity);