//
// Created by Erik on 1/24/2023.
//

#include "ProgressBar.h"
#include "multiProgressBar.h"

void MultiProgressBar::addChild(ProgressBar& child)
{
	this->totalIterations += child.totalIterations;
	child.parent = this;
}

MultiProgressBar::MultiProgressBar(std::optional<std::string> desc, int position, char filledChar, char notFilledChar)
	: ProgressBar(0, desc, 0, position, filledChar, notFilledChar)
{

}