#include <iostream>
#include <thread>
using namespace std;

void counter(int id, int numIteratons)
{
	for (int i = 0; i < numIteratons; ++i) {
		cout << "Counter " << id << " has value ";
		cout << i << endl;
	}
}

int main()
{
	thread t1(counter, 1, 6);
	thread t2(counter, 2, 4);
	t1.join();
	t2.join();

	return 0;
}
