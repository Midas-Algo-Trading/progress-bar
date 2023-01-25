#include <windows.h>
#include "consoleWindows.h"
#include <iostream>
//
// Created by Erik on 1/22/2023.
//
void windowsConsoleWindow::resetCursorPosition() const
{
	SetConsoleCursorPosition(this->h, this->bufferInfo.dwCursorPosition);
}

windowsConsoleWindow::windowsConsoleWindow()
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
	this->width = bufferInfo.dwSize.X;
}
