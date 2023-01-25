// C++ Programming Example No.6

#include <iostream>
#include <string>
#include "ProgressBar.h"
#include "multiProgressBar.h"
#include <thread>

int main()
{
	int total = 0;
	MultiProgressBar mBar("MultiBar", 0);
	ProgressBar pBar1(100, "ProgressBar1", 1);
	ProgressBar pBar2(100, "ProgressBar2", 2);
	mBar.addChild(pBar1);
	mBar.addChild(pBar2);
	for (int i = 0; i < 100; i++)
	{
		pBar1.tick(1);
		for (int j = 0; j < 50000000; j++) {
			total += j * j;
		}
		pBar2.tick(1);
		for (int j = 0; j < 50000000; j++) {
			total += j * j;
		}
	}
	std::cout << total << std::endl;
}































