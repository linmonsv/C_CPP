#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
	vector<int> myVector(10);
	iota(begin(myVector), end(myVector), 1);
	copy(cbegin(myVector), cend(myVector), ostream_iterator<int>(cout, " "));

	return 0;
}
