#include "TimeDate.h"

void TimeDate::print()
{
	std::cout << getDD() << "." << getMM() << "." << getGG() << " " << getH() << " : " << getM() << " : " << getS();
}
