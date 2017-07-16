#include <iostream>
using namespace std;

template<unsigned char f>
class Factorail
{
public:
	static const unsigned long long val = (f * Factorail<f - 1>::val);
};

template<>
class Factorail<0>
{
public:
	static const unsigned long long val = 1;
};

int main()
{
	cout << Factorail<6>::val << endl;

	return 0;
}
