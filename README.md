# Progress Bar
### Simple C++ progress bar
My first C++ project

# Example
### main.cpp
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
![ezgif com-video-to-gif](https://github.com/Midas-Algo-Trading/progress-bar/assets/67431462/099bd34a-4250-48db-abfb-753c8000a7b4)

## Note
This was my first C++ project so the code is not good and has bugs. But being that it was my first C++ project, that is ok :)
