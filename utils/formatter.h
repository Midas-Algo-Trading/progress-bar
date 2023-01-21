//
// Created by Erik on 1/20/2023.
//

#ifndef PROGRESS_BAR_FORMATTER_H
#define PROGRESS_BAR_FORMATTER_H

#endif //PROGRESS_BAR_FORMATTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <cmath>


template<class T>
std::string formatWithCommas(T value)
{
	std::stringstream ss;
	ss.imbue(std::locale(""));
	ss << std::fixed << value;
	return ss.str();
}

std::string formatTime(int seconds)
{
	int minutes = seconds / 60;
	int hours = minutes / 60;

	std::string ret;

	if (hours)
	{
		if (hours < 10) { ret += "0" + std::to_string(hours); }
		else { ret += std::to_string(hours); }
		ret += ':';
	}
	if (minutes < 10) { ret += "0" + std::to_string(minutes); }
	else { ret += std::to_string(minutes); }
	ret += ':';
	if (seconds < 10) { ret += "0" + std::to_string(seconds); }
	else { ret += std::to_string(seconds);}

	return ret;
}

std::string roundNumber(float& num, int dec)
{
	std::ostringstream out;
	out.precision(dec);
	out << std::fixed << num;
	return out.str();
}

