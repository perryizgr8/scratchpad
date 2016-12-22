//Set Bits
//bit      Adobe    Brocade    Cisco    Juniper Networks
//Given a positive integer N, print count of set bits in it. For example, if the given number is 6, output should be 2 as there are two set bits in it.
//
//Input:
//
//The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The next T lines will contain an integer N.
//
//Output:
//Corresponding to each test case, in a new line, print count of set bits in it.
//
//Constraints:
//
//1 ≤ T ≤ 100
//
//1 ≤ N ≤ 1000000
//
//
//Example:
//
//Input:
//
//2
//6
//11
// 
//
//Output:
//2
//3

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		uint64_t num;
		int count = 0;
		std::cin >> num;
		for (int j = 0; j < 64; j++) {
			if ((num >> j) & 1) {
				count++;
			}
		}
		std::cout << count << std::endl;
	}
	return 0;
}
