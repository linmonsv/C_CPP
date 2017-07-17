#include <iostream>
#include <thread>
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
			cout << "Counter " << mId << " has value ";
			cout << i << endl;
		}
	}
private:
	int mId;
	int mNumIterations;
};

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
