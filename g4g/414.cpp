//Missing number in array
//array  searching      Amazon    Microsoft    Payu
//Given an array of size n-1 and given that there are numbers from 1 to n with one missing, the missing number is to be found.
//
//Input:
//
//The first line of input contains an integer T denoting the number of test cases.
//The first line of each test case is N,size of array.
//The second line of each test case contains N-1 input C[i],numbers in array.
//
//Output:
//
//Print the missing number in array.
//
//Constraints:
//
//1 ≤ T ≤ 100
//1 ≤ N ≤ 1000
//1 ≤ C[i] ≤ 1000
//
//Example:
//
//Input
//2
//5
//1 2 3 5
//10
//1 2 3 4 5 6 7 8 10
//
//Output
//4
//9

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

int main()
{
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		std::cin >> N;
		std::vector<int> arr;
		for (int j = 0; j < N - 1; j++) {
			int temp;
			std::cin >> temp;
			arr.push_back(temp);
		}
		int tally = 1;
		for (auto elem : arr) {
			if (tally == elem) {
				tally++;
			}
			else
			{
				std::cout << tally << std::endl;
				break;
			}
		}
	}
	return 0;
}