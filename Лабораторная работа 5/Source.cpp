#include "Carrier.h";
#include "Plane.h";
#include "Car.h";
#include "Train.h";
#include <iostream>
int main() {

	Plane p{ 123, "big" };
	std::cout << "New plane\n";
	Car c{ 124, "small" };
	std::cout << "New car\n";
	Train t{ 125, "medium" };
	std::cout << "New train\n";

	std::cout << "Insert distance:\n";
	double dist;
	std::cin >> dist;
	std::cout << "Plane's price: " << p.calcPrice(dist) << "\n";
	std::cout << "Car's price: " << c.calcPrice(dist) << "\n";
	std::cout << "Train's price: " << t.calcPrice(dist) << "\n";
}