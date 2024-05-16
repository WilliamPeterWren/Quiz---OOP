#pragma once

#include "Encrypt.h"
#include "OOP.h"
#include "Color.h"
#include "Function.h"


void UserName();

void PrintWilliam();

void PrintHacked();

void Reconnect();

void ConvertTime(double& real_time);

void FunnyTime(const short& real_time, short quantity);

void FunnyGrade(const float& grade);

int CheckInput(const std::wstring& temp, int& count_negative, int& count_positive);
