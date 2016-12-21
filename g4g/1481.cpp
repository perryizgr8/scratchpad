//Equal Point in Sorted Array
//array  
//Given a sorted array A of size N, the task is to find whether an element exists in the array from where number of smaller elements is equal to number of greater elements. If Equal Point appears multiple times in input array, print the index of its first occurrence. If Equal Point doesn't exists then print -1.
//
//Examples :
//
//Input  : arr[] = {1, 2, 3, 3, 3, 3}
//Output : 1
//Equal Point is arr[1] which is 2. Number of
//elements smaller than 2 and greater than 2 
//are same.
//
//Input  : arr[] = {1, 2, 3, 3, 3, 3, 4, 4}
//Output : -1
//
//Input : arr[] = {1, 2, 3, 4, 4, 5, 6, 6, 6, 7}
//Output : 3
//First occurrence of equal point is arr[3]
//
//Input:
//The first line of input contains T denoting the no of test cases . Then T test cases follow . The first line of each test case contains an Integer N and the next line contains N space separated values of the array A[ ] .
//
//Output:
//For each test case output the required result in a new line.
//
//Constraints:
//1<=T<=100
//1<=N<=100
//1<=A[ ] <=100
//
//Example:
//Input:
//2
//6
//1 2 3 3 3 3
//8
//1 2 3 3 3 3 4 4
//Output:
//1
//-1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::vector <int> arr, arr_full;
		int elems;
		std::cin >> elems;
		for (int j = 0; j < elems; j++) {
			int temp;
			std::cin >> temp;
			if (std::find(arr.begin(), arr.end(), temp) == arr.end()) {
				arr.push_back(temp);
			}
			arr_full.push_back(temp);
		}
		if (arr.size() % 2 == 0) {
			std::cout << -1 << std::endl;
		}
		else {
			auto idx = std::find(arr_full.begin(), arr_full.end(), arr.at((arr.size() / 2 + 1 - 1)));
			std::cout << idx - arr_full.begin() << std::endl;
		}
	}
	return 0;
}
