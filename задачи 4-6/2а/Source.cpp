#include "ContinuedFraction.h"
#include <iostream>
int main() {
	std::vector<double> arr{ 1.2, 1.5, 6, 7, 8 };
	ContinuedFraction cf(arr, 0.5);
	std::cout << "Insert x: ";
	double x;
	std::cin >> cf;
	std::cout << cf;
}