#include <iostream>
#include <vector>
#include <mutex>
#include <future>
using namespace std;

int calculate()
{
	throw runtime_error("Exception thrown from a thread.");
	return 123;
}

int main()
{
	auto fut = async(launch::async, calculate);
	try {
		int res = fut.get();
		cout << res << endl;
	}
	catch (const exception& ex) {
		cout << "Caught exception: " << ex.what() << endl;
	}

	return 0;
}
