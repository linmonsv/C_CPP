#include <iostream>
#include <vector>
#include <mutex>
using namespace std;

once_flag gOnceFlag;
void initializeShareResources()
{
	cout << "Shared resources initialized." << endl;
}

void processingFunction()
{
	call_once(gOnceFlag, initializeShareResources);
	cout << "Processing" << endl;
}

int main()
{
	vector<thread> threads(3);
	for (auto& t : threads) {
		t = thread(processingFunction);
	}
	for (auto& t : threads) {
		t.join();
	}

	return 0;
}
