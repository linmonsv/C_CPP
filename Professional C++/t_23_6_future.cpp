#include <iostream>
#include <vector>
#include <mutex>
#include <future>
using namespace std;

int calculate()
{
	return 123;
}

int main()
{
	auto fut = async(calculate);
	int res = fut.get();
	cout << res << endl;

	return 0;
}
