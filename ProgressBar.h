//
// Created by Erik on 1/20/2023.
//

#ifndef PROGRESS_BAR_PROGRESSBAR_H
#define PROGRESS_BAR_PROGRESSBAR_H

//
// Created by Erik on 1/20/2023.
//

#include <string>
#include <iostream>
#include <optional>
#include <windows.h>
#include <chrono>
#include <vector>
#include "consoleWindows.h"

class ProgressBar {
    friend class MultiProgressBar;

    public:
	int totalIterations;
	std::optional<std::string> desc;
	int n;
	int position;
	char filledChar;
	char notFilledChar;
    private:
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long long, std::ratio<1, 1000000000>>> startTime;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long long, std::ratio<1, 1000000000>>> lastIterTime;
    protected:
	std::optional<ProgressBar *> parent;
    protected:
	void setConsoleWindow();
    private:
	windowsConsoleWindow console;
	float getPctCompleted() const;
	void printProgressBar(float& iterElapsedTime) const;
	int getDurationSeconds() const;
	int getTimeRemaining() const;
    public:
	ProgressBar(int, std::optional<std::string> = std::optional<std::string>(), int = 0, int = 0, char = '#', char = '-');
	void tick(int by);
	ProgressBar& operator++(int by);
};

#endif //PROGRESS_BAR_PROGRESSBAR_H
