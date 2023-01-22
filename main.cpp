// C++ Programming Example No.6

#include <iostream>
#include <string>
#include "pbar.h"
#include <thread>

int main()
{
	int total = 0;
	pbar pBar(100, "Testing");
	for (int i = 0; i < 100; i++)
	{
		pBar.tick(1);
		for (int j = 0; j < 100000000; j++) {
			total += j * j;
		}
	}
	std::cout << total << std::endl;
}































