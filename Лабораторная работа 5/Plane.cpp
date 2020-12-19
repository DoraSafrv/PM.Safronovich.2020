#include <iostream>
#include "Plane.h"

int Plane::calcPrice(double distance) {
	return distance * getPriceFactor();
}

void Plane::Show() {
	std::cout << "Plane";
}

void Plane::Sound() {
	std::cout << "phhh";
}
