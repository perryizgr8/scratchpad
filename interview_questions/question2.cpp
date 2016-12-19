#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	int64_t num = 0, store = 0;
	std::vector <int> res;
	std::cin >> num;
	store = num;
	if (num == 0) {
		std::cout << -1;
		//std::cin >> num; //to wait
		return 0;
	}
	else if (num == 1) {
		std::cout << 1;
		//std::cin >> num; //to wait
		return 0;
	}

	while (num > 1) {
		if ((num % 9) == 0)
		{
			res.push_back(9);
			num = num / 9;
		}
		else if ((num % 8) == 0) {
			res.push_back(8);
			num = num / 8;
		}
		else if ((num % 7) == 0) {
			res.push_back(7);
			num = num / 7;
		}
		else if ((num % 6) == 0) {
			res.push_back(6);
			num = num / 6;
		}
		else if ((num % 5) == 0) {
			res.push_back(5);
			num = num / 5;
		}
		else if ((num % 4) == 0) {
			res.push_back(4);
			num = num / 4;
		}
		else if ((num % 3) == 0) {
			res.push_back(3);
			num = num / 3;
		}
		else if ((num % 2) == 0) {
			res.push_back(2);
			num = num / 2;
		}
		else {
			std::cout << -1;
			//std::cin >> num; //to wait
			return 0;
		}
	}
	
	std::cout << res.size();
	//std::cin >> num; //to wait
    return 0;
}

