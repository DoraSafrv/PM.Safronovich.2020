#include "TimeDate.h"

void TimeDate::print()
{
	if (isMorning) {
		std::cout << getDD() << "." << getMM() << "." << getGG() << " " << getH() << " : " << getM() << " : " << getS() << " - " << "morning";

	}
	else {
		std::cout << getDD() << "." << getMM() << "." << getGG() << " " << getH() << " : " << getM() << " : " << getS() << " - " << "evening";

	}
}
