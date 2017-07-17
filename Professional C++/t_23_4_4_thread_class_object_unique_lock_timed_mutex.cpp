#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Counter
{
public:
	Counter(int id, int numIterations)
		: mId(id), mNumIterations(numIterations)
	{

	}

	void operator()() const
	{
		for (int i = 0; i < mNumIterations; ++i) {
			unique_lock<timed_mutex> lock(mTimedMutex, 200ms);
			if (lock) {
				cout << "Counter " << mId << " has value ";
				cout << i << endl;
			}
			else {

			}
		}
	}
private:
	int mId;
	int mNumIterations;
	static timed_mutex mTimedMutex;
};
timed_mutex Counter::mTimedMutex;

void counter(int id, int numIteratons)
{
	for (int i = 0; i < numIteratons; ++i) {
		cout << "Counter " << id << " has value ";
		cout << i << endl;
	}
}

int main()
{
	thread t1{ Counter(1, 2) };

	Counter c(2, 12);
	thread t2(c);

	thread t3(Counter(3, 10));

	t1.join();
	t2.join();
	t3.join();

	return 0;
}
