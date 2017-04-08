#include <iostream>
#include <math.h>

double sigma(double(*fn)(double, double), double l, double u)
{
	return (fn(l, u));
}

double fnSinSum(double l, double u)
{
	auto r = 0.0;
	for (auto i = l; i <= u; i += 0.1)
		r += sin(i);
	return r;
}

double fnCosSum(double l, double u)
{
	auto r = 0.0;
	for (auto i = l; i <= u; i += 0.1)
		r += cos(i);
	return r;
}

int main()
{

	std::cout << sigma(fnSinSum, 0.1, 1.0) << std::endl;
	std::cout << sigma(fnCosSum, 0.5, 3.0) << std::endl;

    return 0;
}

