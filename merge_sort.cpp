// scratch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

auto merge(std::vector<int> arr1, std::vector<int> arr2)
{
	auto i = arr1.begin();
	auto j = arr2.begin();
	std::vector<int> merged;
	while ((i != arr1.end()) &&(j != arr2.end()))
	{
		if (*i < *j) {
			merged.push_back(*i);
			i++;
		}
		else if (*j < *i) {
			merged.push_back(*j);
			j++;
		}
		else {
			merged.push_back(*i);
			i++;
			merged.push_back(*j);
			j++;
		}
	}
	while (i != arr1.end())
	{
		merged.push_back(*i);
		i++;
	}
	while (j != arr2.end())
	{
		merged.push_back(*j);
		j++;
	}

	return merged;
}

std::vector<int> merge_sort(std::vector<int> arr)
{
	if (arr.size() > 1) {
		//call merge_sort on two halves
		std::vector<int>::const_iterator first_half_begin = arr.begin();
		std::vector<int>::const_iterator first_half_end = arr.begin() + (arr.size()/2);
		std::vector<int> first_half(first_half_begin, first_half_end);
		auto arr1 = merge_sort(first_half);
		std::vector<int>::const_iterator second_half_begin = arr.begin() + (arr.size()/2);
		std::vector<int>::const_iterator second_half_end = arr.end();
		std::vector<int> second_half(second_half_begin, second_half_end);
		auto arr2 = merge_sort(second_half);

		//merge
		arr = merge(arr1, arr2);
	}
	return arr;
}

int main()
{
	int num;
	std::vector<int> arr;
	std::cin >> num;
	for (int i = 0, temp = 0; i < num; i++) {
		std::cin >> temp;
		arr.push_back(temp);
	}

	arr = merge_sort(arr);

	for (auto i : arr) {
		std::cout << i << '\t';
	}

    return 0;
}

