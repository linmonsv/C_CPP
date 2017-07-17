#include <iostream>
#include <mutex>
using namespace std;

mutex mut1;
mutex mut2;

void process()
{
	unique_lock<mutex> lock1(mut1, defer_lock_t());
	unique_lock<mutex> lock2(mut1, defer_lock_t());
	lock(lock1, lock2);
}

int main()
{
	process();

	return 0;
}
