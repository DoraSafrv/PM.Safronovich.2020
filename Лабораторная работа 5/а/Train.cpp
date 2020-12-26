#include "Train.h"
#include <iostream>
int Train::calcPrice(double distance)
{
	return distance * getPriceFactor();
}

void Train::Show()
{
	std::cout << "chu-chu";
}

void Train::Sound()
{
	std::cout << "chu-chu";
}
