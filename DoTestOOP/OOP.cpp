#include "OOP.h"

// constructor
OOP::OOP() {
	this->question = L"";
	this->answer_a = L"";
	this->answer_b = L"";
	this->answer_c = L"";
	this->answer_d = L"";
	this->check_answer = L"";
	this->answer = L"";
}

// destructor
OOP::~OOP() {
	this->question = L"";
	this->answer_a = L"";
	this->answer_b = L"";
	this->answer_c = L"";
	this->answer_d = L"";
	this->check_answer = L"";
	this->answer = L"";
}

// getter
std::wstring OOP::getQuestion() {
	return this->question;
}

std::wstring OOP::getAnswer_a() {
	return this->answer_a;
}

std::wstring OOP::getAnswer_b() {
	return this->answer_b;
}

std::wstring OOP::getAnswer_c() {
	return this->answer_c;
}

std::wstring OOP::getAnswer_d() {
	return this->answer_d;
}

std::wstring OOP::getCheck_answer() {
	return this->check_answer;
}

std::wstring OOP::getAnswer() {
	return this->answer;
}

 //setter
void OOP::setQuestion(std::wstring question) {
	this->question = question;
}

void OOP::setAnswer_a(std::wstring answer_a) {
	this->answer_a = answer_a;
}
void OOP::setAnswer_b(std::wstring answer_b) {
	this->answer_b = answer_b;
}
void OOP::setAnswer_c(std::wstring answer_c) {
	this->answer_c = answer_c;
}
void OOP::setAnswer_d(std::wstring answer_d) {
	this->answer_d = answer_d;
}

void OOP::setCheck_answer(std::wstring check_answer) {
	this->check_answer = check_answer;
}

void OOP::setAnswer(std::wstring answer) {
	this->answer = answer;
}