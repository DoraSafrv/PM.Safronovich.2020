#include "Time.h"

void Time::printT()
{
	if (isMorning) {
		std::cout << h << " : " << m << " : " << s << " - " << "morning";

	}
	else {
		std::cout << h << " : " << m << " : " << s << " - " << "evening";

	}
}
