#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <io.h> //set_mode()
#include <fcntl.h> //_O_WTEXT
#include <fstream>
#include <codecvt>
#include <vector>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <set>
#include <sstream>
#include <thread>


/*
	0 black			1 blue				2 green				3 aqua
	4 red			5 purple			6 yellow			7 white
	8 gray			9 light blue		10 light green		11 light aqua
	12 light red	13 light purple		14 light yellow		15 bright white
*/

#define black 0
#define blue 1
#define green 2
#define aqua 3
#define red 4
#define purple 5
#define yellow 6
#define white 7
#define gray 8
#define lightblue 9
#define lightgreen 10
#define lightaqua 11
#define lightred 12
#define lightpurple 13
#define lightyellow 14
#define lightwhite 15


class OOP {
private:
	std::wstring question, answer_a, answer_b, answer_c, answer_d, check_answer, answer;

public:

	// constructor
	OOP();

	// destructor
	~OOP();

	// getter
	std::wstring getQuestion();

	std::wstring getAnswer_a();

	std::wstring getAnswer_b();

	std::wstring getAnswer_c();

	std::wstring getAnswer_d();

	std::wstring getCheck_answer();

	std::wstring getAnswer();

	// setter
	void setQuestion(std::wstring question);

	void setAnswer_a(std::wstring answer_a);

	void setAnswer_b(std::wstring answer_b);

	void setAnswer_c(std::wstring answer_c);

	void setAnswer_d(std::wstring answer_d);

	void setCheck_answer(std::wstring check_answer);

	void setAnswer(std::wstring answer);
};