//Distance and Displacement
//maths  
//Sherlock is going to walk to the store. On his way to the store he likes to visit his friends and stop at various other interesting places.On his way back he is carrying heavy bags and therefore he walks straight home. Sherlock's walk from his home to the store consists of M parts. In the i-th part (0-based index) sherlock will walk a[i] meters in the direction indicated by the character dir[i]. That character is one of 'N', 'S', 'W', 'E', denoting North, South, West, and East, respectively. On his way back home, Sherlock follows a straight line from the store to his home​.
//
//Input: 
//Each test case contains an integer T denoting the no of test cases, then T test cases follow. First line of each test case contains an integer M. In the next two line you are given the description of Sherlock's way to the store, the array with M integers and the string with M uppercase characters. Your task is to print the total distance Sherlock will walk on his way to the store and back.
//
//Output:
//For each test case output will be an integer which represents the ceil of the total distance covered by Sherlock. 
//
//Constraints: 
//1<=T<=15
//1<=M<=100
//
//Example:
//Input:
//2
//3
//1 3 3
//NES
//4
//10 10 10 10
//NWSE
//
//Output:
//11
//40
//
//Explanation :
//For test case 1
//In total, Sherlock's walk consists of four parts: He goes 1 meter North. 3
//meters East. 3 meters South. He goes straight to his home. The total distance is 1 + 3 + 3 + 3.6056 = 10.6056. so the ceil of it is 11.
//
//For test case 2
//In this test case the store is located at the same place as Sherlock's home. Thus, the length of
//Sherlock's walk from the store back home is 0 meters.

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

class Vect
{
public:
	Vect();
	Vect(int64_t a, int64_t b);
	~Vect();
	double magnitude();
	Vect operator+(Vect a);

private:
	int64_t x;
	int64_t y;

};

Vect::Vect(int64_t a, int64_t b)
{
	x = a;
	y = b;
}

Vect::Vect()
{
}

Vect::~Vect()
{
}

double Vect::magnitude()
{
	double temp = pow(x, 2) + pow(y, 2);
	temp = sqrt(temp);
	return temp;
}

Vect Vect::operator+(Vect a)
{
	Vect sum(0,0);
	sum.x = this->x + a.x;
	sum.y = this->y + a.y;
	return sum;
}

struct inputs {
	int mag;
	char direc;
};

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int steps = 0;
		std::cin >> steps;
		std::vector <Vect> directions;
		std::vector <struct inputs> ip(steps);
		for (int j = 0; j < steps; j++) {
			int temp;
			std::cin >> temp;
			ip[j].mag = temp;
		}
		std::string dirstr;
		std::cin >> dirstr;
		int count = 0;
		for (char c : dirstr) {
			ip[count].direc = c;
			count++;
		}

		for (int j = 0; j < steps; j++) {
			int64_t x = 0;
			int64_t y = 0;
			if (ip[j].direc == 'N') {
				x = 0;
				y = ip[j].mag;
			}
			else if (ip[j].direc == 'S') {
				x = 0;
				y = -1 * ip[j].mag;
			}
			else if (ip[j].direc == 'E') {
				x = ip[j].mag;
				y = 0;
			}
			else if (ip[j].direc == 'W') {
				x = -1 * ip[j].mag;
				y = 0;
			}
			Vect temp(x, y);
			directions.push_back(temp);
		}
		
		//final coordinates
		Vect finco(0, 0);
		double distance = 0;
		for (auto step : directions) {
			finco = finco + step;
			distance += step.magnitude();
		}
		distance += finco.magnitude();
		std::cout << ceil(distance) << std::endl;
	}
	return 0;
}