//Minimize string value
//string      Amazon
//Given a string of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters.  The value of a string is defined as sum of squares of count of each distinct character. For example consider the string “saideep”, here frequencies of characters are s-1, a-1, i-1,e-2, d-1, p-1 and value of the string is 1^2 + 1^2 + 1^2 + 1^2 + 1^1 + 2^2 = 9.
//
//Input:
//The first line of input contains the number T denoting the no of test cases . Then T test cases follow. .Each test case contains two lines.The first line of each test case contains a string str. The second line of each test case consist of an integer k .
//
//Output:
//The output for each test case will be an integer denoting the min possible value of the string.
//
//Constraints:
//1<=T<=100 
//1<=str<=50
//1<=k<=50
//
//Example:
//Input
//2
//abccc
//1
//aaab
//2
//Output
//6
//2
//
//2
//svbspkyh
//39
//0
//vtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbs
//12
//47

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

int getval(std::vector<std::pair<char, int>> freqmap)
{
	int val = 0;
	for (auto itr : freqmap) {
		val += itr.second*itr.second;
	}
	return val;
}

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string yolo;
		
		std::map<char, int> freqmap;
		std::cin >> yolo;
		for (auto chr : yolo) {
			auto prev = freqmap.find(chr);
			if (prev != freqmap.end()) {
				prev->second++;
			}
			else {
				freqmap.insert(std::pair<char, int>(chr, 1));
			}
		}
		std::vector<std::pair<char, int>> brainhurtz;
		for (auto pair : freqmap) {
			brainhurtz.push_back(pair);
		}
		int k;
		std::cin >> k;
		if (k > yolo.length()) {
			std::cout << 0 << std::endl;
			continue;
		}
		for (int i = k; i > 0; i--) {
			//get max element
			int max = 0;
			std::pair<char, int> *maxel;
			for (int p = 0; p < brainhurtz.size(); p++) {
				auto pair = &brainhurtz[p];
				if (pair->second > max) {
					maxel = pair;
					max = pair->second;
				}
			}
			//and decrement it
			maxel->second--;
		}
		int cost = getval(brainhurtz);
		std::cout << cost << std::endl;
	}
	return 0;
}