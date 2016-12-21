//Elements before which no element is bigger
//array  
//Given an array of integers, the task is to find count of elements before which all the elements are smaller. First element is always counted as there is no other element before it.
//
//Input:
//
//The first line of input will contain no of test cases T . Then T test cases follow . Each test case contains 2 lines. The first line of each test case contains an integer N denoting the number of elements in the array, the next line contains N space separated integer's denoting the elements of the array.
//
//
//Output:
//
//For each test case in new line print the Number of Elements before which no element is bigger
//
//
//Constraints:
//
//1<=T<=100
//
//1<=N<=1000
//
//
//Example:
//
//Input
//
//2
//6
//10 40 23 35 50 7
//3
//5 4 1
//
//Output
//
//3
//1
//
//Explanation:
//
//Test Case 1
//Input: arr[] =  {10, 40, 23, 35, 50, 7}
//Output: 3
//The elements are 10, 40 and 50.
//No of elements is 3
//
//Test Case 2
//Input: arr[] = {5, 4, 1}
//Output: 1
//There is only one element 5
//No of element is 1

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
	//code
	int N, num_el, ans = 0;
	std::vector <int> arr;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num_el;
		for (int j = 0; j < num_el; j++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}


		int minint = numeric_limits<int>::min();

		for (auto num : arr) {
			if (minint < num) {
				minint = num;
				ans++;
			}
		}
		cout << ans << endl;
		ans = 0;
		arr.clear();
	}
	return 0;
}