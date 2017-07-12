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

	istream_iterator<int> numbersIter(cin);
	istream_iterator<int> endIter;
	int sum = accumulate(numbersIter, endIter, 0);
	cout << "Sum: " << sum << endl;

	return 0;
}
