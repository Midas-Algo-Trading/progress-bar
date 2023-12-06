#include "ProgressBar.h"
#include "multiProgressBar.h"
#include <thread>

int main()
{
	MultiProgressBar mBar("MultiBar", 0);
	ProgressBar pBar1(100, "ProgressBar1", 1);
	ProgressBar pBar2(100, "ProgressBar2", 2);
	mBar.addChild(pBar1);
	mBar.addChild(pBar2);
	for (int i = 0; i < 200; i++)
	{
		if (i % 2 == 0)
			pBar1.tick(1);
		if (i < 100)
			pBar2.tick(1);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}































