//
// Created by Erik on 1/20/2023.
//

#ifndef PROGRESS_BAR_PBAR_H
#define PROGRESS_BAR_PBAR_H

//
// Created by Erik on 1/20/2023.
//

#include <string>
#include <iostream>
#include <optional>
#include <windows.h>
#include <chrono>

class pbar
{
    public:
	int total;
	int n = 50;
	std::optional<std::string> desc;
	char filledChar;
	char notFilledChar;
    private:
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long long, std::ratio<1, 1000000000>>> startTime;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long long, std::ratio<1, 1000000000>>> lastIterTime;
    private:
	unsigned short getConsoleWidth() const;
	float getPctCompleted() const;
	void printProgressBar(float iterElapsedTime) const;
	int getDurationSeconds() const;
	int getTimeRemaining() const;
    public:
	pbar(int = 100, int = 0, std::optional<std::string> = std::optional<std::string>(), char = '#', char = '-');
	void tick(int by);
};

#endif //PROGRESS_BAR_PBAR_H
