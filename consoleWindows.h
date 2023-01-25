//
// Created by Erik on 1/22/2023.
//

#ifndef PROGRESS_BAR_CONSOLEWINDOWS_H
#define PROGRESS_BAR_CONSOLEWINDOWS_H

#include <thread>
#include <windows.h>

class consoleWindow
{
    public:
	int width;
    public:
	virtual void resetCursorPosition() const {};
};

class windowsConsoleWindow : public consoleWindow
{
    public:
	windowsConsoleWindow();
	void resetCursorPosition() const;
    private:
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	_CONSOLE_SCREEN_BUFFER_INFO bufferInfo{};
};

#endif //PROGRESS_BAR_CONSOLEWINDOWS_H
