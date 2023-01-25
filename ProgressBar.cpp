//
// Created by Erik on 1/20/2023.
//

#include <string>
#include <optional>
#include <utility>
#include <windows.h>
#include <chrono>
#include "ProgressBar.h"
#include "utils/formatter.h"
#include "consoleWindows.h"

ProgressBar::ProgressBar(int total, std::optional<std::string> desc, int position, int n, char filledChar, char notFilledChar)
	: totalIterations(total), desc(std::move(desc)), n(n), position(position), filledChar(filledChar), notFilledChar(notFilledChar)
{
	// Set the start time.
	this->startTime = std::chrono::high_resolution_clock::now();

	this->setConsoleWindow();
}

float ProgressBar::getPctCompleted() const { return (float) n / (float) this->totalIterations; }

void ProgressBar::setConsoleWindow()
{
	#ifdef _WIN32
		this->console = windowsConsoleWindow();
	#endif
}


void ProgressBar::printProgressBar(float& iterElapsedTime) const
{
	// Create the description.
	std::string _description = this->desc ? desc.value() + ": " : "";

	// Create the percent completed.
	std::string _pctCompleted = std::to_string((int) (100 * this->getPctCompleted()));

	// Create the iterations.
	std::string _iterations = formatWithCommas<int>(n) + "/" + formatWithCommas<int>(this->totalIterations);

	// Create the elapsed and estimated time.
	std::string _times = formatTime(this->getDurationSeconds()) + "<" + formatTime(this->getTimeRemaining());

	// Create the iterations/second.
	std::string _itersSecond = roundNumber(iterElapsedTime, 2);

	// Create the bar
	short totalBarWidth = -_description.length() - 4 - 1 + this->console.width - 2 - _iterations.length() - 2 - _times.length() - 31;
	short barCompletedLength = totalBarWidth * getPctCompleted();
	short barIncompleteLength = totalBarWidth - barCompletedLength;
	std::string _bar = "|" + std::string(barCompletedLength, this->filledChar) + std::string(barIncompleteLength, this->notFilledChar) + "|";

	// Reset the cursor position before printing.
	this->console.resetCursorPosition();

	for (int i = 0; i < this->position; i++) {
		std::cout << "\n";
	}

	std::cout << _description << _pctCompleted << "% " << _bar << ' ' << _iterations << " [" << _times << ", " << _itersSecond << "it/s]" << std::flush;
}

void ProgressBar::tick(int by)
{
	auto now = std::chrono::high_resolution_clock::now();
	float iterElapsedTime = 1000000.0f / static_cast<float>(std::chrono::duration_cast<std::chrono::microseconds>(now - this->lastIterTime).count());

	this->n += by;
	this->printProgressBar(iterElapsedTime);
	this->lastIterTime = now;

	if (parent)
	{
		parent.value()->tick(by);
	}
}

int ProgressBar::getDurationSeconds() const
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	return static_cast<int>(std::chrono::duration_cast<std::chrono::seconds>(currentTime - this->startTime).count());
}

int ProgressBar::getTimeRemaining() const { return ((1 / this->getPctCompleted()) - 1) * getDurationSeconds(); }

ProgressBar& ProgressBar::operator++(int by)
{
	this->tick(by);
	return *this;
}
