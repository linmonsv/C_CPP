#include <iostream>
#include <string>
#include <functional>
using namespace std;

#if 0
template<int n, typename TupleType>
class tuple_print
{
public:
	tuple_print(const TupleType t) {
		tuple_print<n - 1, TupleType> tp(t);
		cout << get<n - 1>(t) << endl;
	}
};

template<typename TupleType>
class tuple_print<0, TupleType>
{
public:
	tuple_print(const TupleType&) { }
};
#endif

template<int n, typename TupleType>
class tuple_print_helper
{
public:
	tuple_print_helper(const TupleType& t) {
		tuple_print_helper<n - 1, TupleType> tp(t);
		cout << get<n - 1>(t) << endl;
	}
};

template<typename TupleType>
class tuple_print_helper<0, TupleType>
{
public:
	tuple_print_helper(const TupleType&) { }
};

template<typename T>
void tuple_print(const T& t)
{
	tuple_print_helper<tuple_size<T>::value, T> tph(t);
}

/*

*/

int main()
{
	//using MyTuple = tuple<int, string, bool>;
	//MyTuple t1(16, "Test", true);
	//tuple_print<tuple_size<MyTuple>::value, MyTuple> tp(t1);

	auto t1 = make_tuple(167, "Testing", false, 2.3);
	tuple_print(t1);

	return 0;
}
