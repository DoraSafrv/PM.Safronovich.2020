#include "ContinuedFraction.h"
#include "ContinuedFraction.h"
#include <iostream>
std::ostream& operator<<(std::ostream& out, const ContinuedFraction& point) {
	out << point.summ;
	return out;
}

std::istream& operator>>(std::istream& in, ContinuedFraction& point) {
	in >> point.x;
	point.summ = point.calc();
	return in;
}
