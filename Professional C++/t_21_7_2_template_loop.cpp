#include <iostream>
#include <string>
#include <functional>
using namespace std;

template<int i>
class Loop
{
public:
	template <typename FuncType>
	static inline void Do(FuncType func) {
		Loop<i - 1>::Do(func);
		func(i);
	}
};

template<>
class Loop<0>
{
public:
	template <typename FuncType>
	static inline void Do(FuncType) {}
};

void DoWork(int i) { cout << "DoWorkd(" << i << ")" << endl; }

void DoWork2(string str, int i)
{
	cout << "DoWorkd2(" << str << ", " << i << ")" << endl;
}

int main()
{
	Loop<3>::Do(DoWork);

	Loop<2>::Do(bind(DoWork2, "TestStr", placeholders::_1));

	return 0;
}
