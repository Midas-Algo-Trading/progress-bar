//
// Created by Erik on 1/20/2023.
//

#include <string>
#include <optional>
#include <utility>
#include <windows.h>
#include <chrono>
#include "pbar.h"
#include "utils/formatter.h"

pbar::pbar(int total, int n, std::optional<std::string> desc, char filledChar, char notFilledChar)
	: total(total), n(n), desc(std::move(desc)), filledChar(filledChar), notFilledChar(notFilledChar)
{
	this->startTime = std::chrono::high_resolution_clock::now();
	std::cout << "created" << std::endl;
}

float pbar::getPctCompleted() const { return (float) n / (float) total; }

unsigned short pbar::getConsoleWidth() const
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwSize.X;
}

void pbar::printProgressBar(float iterElapsedTime) const
{
	// Create the percent completed.
	std::string _pctCompleted = std::to_string((int) (100 * this->getPctCompleted()));

	// Create the iterations.
	std::string _iterations = formatWithCommas<int>(n) + "/" + formatWithCommas<int>(total);

	// Create the elapsed and estimated time.
	std::string _times = formatTime(this->getDurationSeconds()) + "<" + formatTime(this->getTimeRemaining());

	// Create the iterations/second.
	std::string _itersSecond = roundNumber(iterElapsedTime, 2);

	// Create the bar
	short totalBarWidth = -4 - 1 + getConsoleWidth() - 2 - _iterations.length() - 2 - _times.length() - 31;
	short barCompletedLength = totalBarWidth * getPctCompleted();
	short barIncompleteLength = totalBarWidth - barCompletedLength;
	std::string _bar = "|" + std::string(barCompletedLength, this->filledChar) + std::string(barIncompleteLength, this->notFilledChar) + "|";

	std::cout << "\r" << _pctCompleted << "% " << _bar << " [" << _times << ", " << _itersSecond << "it/s]";
}

void pbar::tick(int by)
{
	auto now = std::chrono::high_resolution_clock::now();
	float iterElapsedTime = 1000000.0f / static_cast<float>(std::chrono::duration_cast<std::chrono::microseconds>(now - this->lastIterTime).count());

	this->n += by;
	this->printProgressBar(iterElapsedTime);
	this->lastIterTime = now;
}

int pbar::getDurationSeconds() const
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	return static_cast<int>(std::chrono::duration_cast<std::chrono::seconds>(currentTime - this->startTime).count());
}

int pbar::getTimeRemaining() const { return ((1 / this->getPctCompleted()) - 1) * getDurationSeconds(); }

