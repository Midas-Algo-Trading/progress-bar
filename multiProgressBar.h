#ifndef PROGRESS_BAR_MULTIPROGRESSBAR_H
#define PROGRESS_BAR_MULTIPROGRESSBAR_H

#include "ProgressBar.h"

class MultiProgressBar : public ProgressBar {
    public:
	void addChild(ProgressBar & child);
    public:
	MultiProgressBar(std::optional<std::string> = std::optional<std::string>(), int = 0, char = '#', char = '-');
};

#endif //PROGRESS_BAR_MULTIPROGRESSBAR_H
