#include<iostream>

double normalCDF(double val) {
	/*
	 Note, this is a typical representation of normal CDF, as
	 the standard C++ library doesn't have that specific function.
	*/
	return .5 * (1 + std::erf(val / std::sqrt(2)));
}

int main() {
	//=========================================Naive approach
	//Get the variables
	std::cout << "Spot price:";
	double s = 0;
	std::cin >> s;

	std::cout << "Strike price:";
	double k = 0;
	std::cin >> k;

	std::cout << "Risk free interest rate:";
	double r = 0;
	std::cin >> r;

	std::cout << "Time to maturity:";
	double t = 0;
	std::cin >> t;

	std::cout << "Volatility of the asset:";
	double v = 0;
	std::cin >> v;

	//Plug them in with no regards to efficiency (yet)
	double d1 = (std::log(s / k) + (r + (v * v) / 2) * t) / v * std::sqrt(t);
	double d2 = d1 - v * std::sqrt(t);
	double C = normalCDF(d1) * s - normalCDF(d2) * k * std::exp(-r * t);

	//(optional: print intermediate steps.)
	//std::cout << d1 << std::endl;
	//std::cout << d2 << std::endl;
	//Print the results

	std::cout << C;
	return 0;
}