#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
using namespace std;

void func(int& counter)
{
	for (int i = 0; i < 100; ++i) {
		++counter;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void func2(std::atomic<int>& counter)
{
	for (int i = 0; i < 100; ++i) {
		++counter;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void func3(std::atomic<int>& counter)
{
	int result = 0;
	for (int i = 0; i < 100; ++i) {
		++result;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	counter += result;
}

int main()
{
	int counter = 0;
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; ++i) {
		threads.push_back(std::thread{ func, std::ref(counter)});
	}
	for (auto& t : threads) {
		t.join();
	}
	std::cout << "Result = " << counter << std::endl;

	{
		std::atomic<int> counter(0);
		std::vector<std::thread> threads;
		for (int i = 0; i < 10; ++i) {
			threads.push_back(std::thread{ func2, std::ref(counter) });
		}
		for (auto& t : threads) {
			t.join();
		}
		std::cout << "Result = " << counter << std::endl;
	}

	{
		std::atomic<int> counter(0);
		std::vector<std::thread> threads;
		for (int i = 0; i < 10; ++i) {
			threads.push_back(std::thread{ func3, std::ref(counter) });
		}
		for (auto& t : threads) {
			t.join();
		}
		std::cout << "Result = " << counter << std::endl;
	}

	return 0;
}
