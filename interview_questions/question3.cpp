#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>


int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

struct fraction {
	int64_t numerator;
	int64_t denominator;
};

auto add_fractions(struct fraction a, struct fraction b)
{
	int div = gcd(a.denominator, b.denominator);
	struct fraction sum { (a.numerator*b.denominator + b.numerator*a.denominator), (a.denominator*b.denominator) };

	sum.numerator /= div;
	sum.denominator /= div;

	div = gcd(sum.numerator, sum.denominator);
	sum.numerator /= div;
	sum.denominator /= div;

	return sum;
}
auto subtract_fractions(struct fraction a, struct fraction b)
{
	int div = gcd(a.denominator, b.denominator);
	struct fraction sum { (a.numerator*b.denominator - b.numerator*a.denominator), (a.denominator*b.denominator) };

	sum.numerator /= div;
	sum.denominator /= div;

	div = gcd(sum.numerator, sum.denominator);
	sum.numerator /= div;
	sum.denominator /= div;

	return sum;
}
void print_seq(std::vector <struct fraction> seq)
{
	int count = 1;
	for (auto i : seq) {
		std::cout << i.numerator << "/" << i.denominator;
		if (count < seq.size()) {
			std::cout << " + ";
			count++;
		}
	}
}


int main(int argc, char **argv)
{
	std::vector <struct fraction> series;
	struct fraction frac, value;
	//long double value;
	if (argc == 3) {
		frac.numerator = atoi(argv[1]);
		frac.denominator = atoi(argv[2]);
		//value = (long double)frac.numerator / (long double)frac.denominator;
	}
	else
	{
		std::cout << -1;
		return 0;
	}
	struct fraction sum = { 0,1 };
	value = frac;
	for (int64_t i = 3; (!((sum.numerator == frac.numerator) && (sum.denominator == frac.denominator))); i += 2) {
		if ((double)1 / (double)i <= (double)value.numerator / (double)value.denominator) {
			struct fraction temp { 1, i };
			series.push_back(temp);
			sum = add_fractions(sum, temp);
			value = subtract_fractions(value, temp);
		}
	}

	print_seq(series);
	return 0;
}