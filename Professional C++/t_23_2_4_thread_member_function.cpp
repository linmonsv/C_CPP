#include <iostream>
#include <thread>
using namespace std;

class Request
{
public:
	Request(int id) : mId(id) { }
	void process()
	{
		cout << "Processing request " << mId << endl;
	}
private:
	int mId;
};

int main()
{
	Request req(100);
	thread t1( &Request::process, &req );

	t1.join();

	return 0;
}
