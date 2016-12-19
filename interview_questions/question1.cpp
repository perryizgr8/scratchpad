#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>


struct fraction {
	int numerator;
	int denominator;
};
struct fraction zero = { 0, 1 };
struct fraction one = { 1, 1 };

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

bool mycomparator(struct fraction i, struct fraction j)
{
	double frac1 = ((double)i.numerator) / ((double)i.denominator);
	double frac2 = ((double)j.numerator) / ((double)j.denominator);
	return (frac1 < frac2);
}

auto get_fractions(int order)
{
	std::vector <struct fraction> fracs;
	for (int numerator = 1; numerator < order; numerator++) {
		for (int denominator = order; denominator > numerator; denominator--) {
			if (gcd(numerator, denominator) == 1)
			{
				struct fraction addthis { numerator, denominator };
				fracs.push_back(addthis);
			}
		}
	}
	return fracs;
}

void print_seq(std::vector <struct fraction> seq)
{
	for (auto i : seq) {
		std::cout << i.numerator << "/" << i.denominator;
		if (!((i.numerator == 1) && (i.denominator == 1)))
		{
			std::cout << ", ";
		}
	}
}

int main(int argc, char **argv)
{
	int num = 0;
	if (argc == 2) {
		num = atoi(argv[1]);
	}
	//std::cin >> num;
	std::vector <struct fraction> seq;
	seq.push_back(zero);
	if (num == 0) {
		std::cout << -1;
		return 0;
	}
	if (num == 1) {
		seq.push_back(one);
		print_seq(seq);
		return 0;
	}

	std::vector <struct fraction> fractions = get_fractions(num);
	std::sort(fractions.begin(), fractions.end(), mycomparator);
	for (auto elem : fractions) {
		seq.push_back(elem);
	}

	seq.push_back(one);
	print_seq(seq);
    return 0;
}