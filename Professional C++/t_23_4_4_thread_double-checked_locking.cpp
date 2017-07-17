#include <iostream>
#include <vector>
#include <mutex>
#include <atomic>
using namespace std;

once_flag gOnceFlag;
void initializeShareResources()
{
	cout << "Shared resources initialized." << endl;
}

atomic<bool> initialized(false);
mutex mut;

void func()
{
	if (!initialized) {
		unique_lock<mutex> lock(mut);
		if (!initialized) {
			initializeShareResources();
			initialized = true;
		}
	}
	cout << "OK" << endl;
}

int main()
{
	vector<thread> threads;
	for (int i = 0; i < 5; ++i) {
		threads.push_back(thread{ func });
	}
	for (auto& t : threads) {
		t.join();
	}

	return 0;
}
