//Rotate by 90 degree
//matrix      Microsoft
//Given an square matrix, turn it by 90 degrees in anti-clockwise direction without using any extra space.
//
//Input:
//
//The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of the square matrix.The second line of each test case contains NxN space separated values of the matrix M.
//
//Output:
//
//Corresponding to each test case, in a new line, print the rotated array.
//
//Constraints:
//
//1 ≤ T ≤ 50
//1 ≤ N ≤ 50
//
//Example:
//
//Input
//1
//3
//1 2 3
//4 5 6
//7 8 9
//
//Output
//3 6 9
//2 5 8
//1 4 7

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print_matrix(std::vector<std::vector<int>> matrix)
{
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			std::cout << matrix[i][j] << " ";
		}
	}
	std::cout << std::endl;
}

auto rotate_matrix(std::vector<std::vector<int>> matrix)
{
	int N = matrix.size();
	for (int x = 0; x < N / 2; x++) {
		for (int y = x; y < N - 1 - x; y++) {
			int temp = matrix[x][y];
			matrix[x][y] = matrix[y][N - 1 - x];
			matrix[y][N - 1 - x] = matrix[N - 1 - x][N - 1 - y];
			matrix[N - 1 - x][N - 1 - y] = matrix[N - 1 - y][x];
			matrix[N - 1 - y][x] = temp;
		}
	}
	return matrix;
}

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int order;
		std::cin >> order;
		std::vector<std::vector<int>> matrix(order);
		for (int i = 0; i < order; i++) {
			matrix[i].resize(order);
		}
		for (int i = 0; i < order; i++) {
			for (int j = 0; j < order; j++) {
				std::cin >> matrix[i][j];
			}
		}
		matrix = rotate_matrix(matrix);
		print_matrix(matrix);
	}
	return 0;
}

