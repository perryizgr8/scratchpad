//Key Pair
//array      Amazon    CarWale
//Given an array A[] of n numbers and another number x, determine whether or not there exist two elements in A whose sum is exactly x.
//
//Input:
//
//The first line of input contains an integer T denoting the number of test cases.
//The first line of each test case is N and X,N is the size of array.
//The second line of each test case contains N integers representing array elements C[i].
//
//Output:
//
//Print "Yes" if there exist two elements in A whose sum is exactly x, else "No" without quotes.
//
//Constraints:
//
//1 ≤ T ≤ 100
//1 ≤ N ≤ 200
//1 ≤ C[i] ≤ 1000
//
//Example:
//
//Input:
//2
//6 16
//1 4 45 6 10 8
//5 10
//1 2 4 3 6
//
//Output:
//Yes
//Yes

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
		if (i != 0) {
			std::cout << std::endl;
		}
		int N, X;
		std::cin >> N >> X;
		std::vector<int> arr;
		for (int j = 0; j < N; j++) {
			int temp;
			std::cin >> temp;
			arr.push_back(temp);
		}
		bool found = false;
		for (int j = 0; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (arr[j] + arr[k] == X) {
					std::cout << "Yes";
					found = true;
				}
				if (found == true) {
					break;
				}
			}
			if (found == true) {
				break;
			}
		}
		if (found == false) {
			std::cout << "No";
		}
	}
	return 0;
}
