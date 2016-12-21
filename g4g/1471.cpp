//No of Carry Operations
//maths  string  
//Given two numbers, the task is to find the number of carry operations required when two numbers are added as below..
//1234
//+
//5678
//--------
//6912
//--------
//4+8 = 2 and carry 1
//carry+3+7 = carry 1
//carry+2+6 = 9, carry 0
//carry+1+5 = 6
//
//We need two carry operations in this example.
//
//Input:
//First line of input consists of an integer T, denoting the no of test cases. Then T test cases follow. Each test case contains two unsigned integers(n1,n2) less than 10 digits.
//
//Output: 
//For each test case in a new line print the number of carry operations that would be required while adding n1 and n2.
//
//Constraints:
//1<=T<=50
//1<=n1, n2 <= 9*10^10
//
//Example:
//Input:
//3
//123 456
//555 555
//123 594
// 
//
//Output:
//0
//3
//1


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <limits>

auto conv2arr(int64_t i) {
	std::vector <int64_t> num;
	while (i) {
		num.push_back(i % 10);
		i /= 10;
	}
	return num;
}

int main() {
	int N;
	std::vector <int64_t> num1, num2, fleet;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int64_t temp, diff;
		std::cin >> temp;
		num1 = conv2arr(temp);
		std::cin >> temp;
		num2 = conv2arr(temp);
		
		if (num1.size() > num2.size()) {
			diff = num1.size() - num2.size();
			for (int d = 0; d < diff; d++) {
				num2.push_back(0);
			}
		}
		else if (num2.size() > num1.size()) {
			diff = num2.size() - num1.size();
			for (int d = 0; d < diff; d++) {
				num1.push_back(0);
			}
		}

		int digits = num1.size();
		bool lastdigcarry = false;
		int ans = 0;
		for (int digit = 0; digit < digits; digit++) {
			if (lastdigcarry == false)
			{
				if ((num1[digit] + num2[digit]) >= 10) {
					ans++;
					lastdigcarry = true;
				}
				else {
					lastdigcarry = false;
				}
			}
			else {
				if ((num1[digit] + num2[digit] + 1) >= 10) {
					ans++;
					lastdigcarry = true;
				}
				else {
					lastdigcarry = false;
				}
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}