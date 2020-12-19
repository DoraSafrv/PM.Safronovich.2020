#include "Money.h"

const Money Money::operator+(const Money& rv) const
{

	int newRub = rub + rv.rub;
	char newKopek = (char)((kopek - '0') + (rv.kopek - '0') + '0');
	if (newKopek >= ':') {
		newRub++;
		newKopek = (char)(newKopek - ':' + '0');
	}
	Money newM{ newRub, newKopek };
	return newM;

}

const Money Money::operator-(const Money& rv) const
{
	if (rub - rv.rub < 0 || (rub - rv.rub == 0 && kopek - rv.kopek <= '0')) return Money(0, '0');
	int newRub = rub - rv.rub;
	char newKopek = (char)(kopek - rv.kopek + '0');
	if (newKopek < '0') {
		newRub--;
		newKopek = (char)(newKopek + 10);
	}
	return Money(newRub, newKopek);
}

bool operator<(const Money& left, const Money& right)
{
	if (right - left == Money(0, '0')) return false;
	return true;
}

bool operator>(const Money& left, const Money& right)
{
	if (left - right == Money(0, '0')) return false;
	return true;
}

bool operator==(const Money& left, const Money& right) {
	if (left.rub == right.rub && left.kopek == right.kopek) return true;
	return false;
}


std::ostream& operator<< (std::ostream& out, const Money& point)
{
	out << point.rub << "." << point.kopek;
	return out;
}

