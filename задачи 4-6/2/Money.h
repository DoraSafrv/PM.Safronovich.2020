#pragma once
#include <ostream>
class Money
{
public:
	Money(int rubIn, char kopekIn) {
		this->kopek = kopekIn;
		this->rub = rubIn;
	}

	void setRub(int rubb) {
		this->rub = rubb;
	}
	void setKopek(int kopekk) {
		this->kopek = kopek;
	}

	int getRub() {
		return rub;
	}

	char getKopek() {
		return kopek;
	}

	const Money operator+(const Money& rv) const;
	const Money operator-(const Money& rv) const;
	friend bool operator<(const Money& left, const Money& right);
	friend bool operator>(const Money& left, const Money& right);
	friend bool operator==(const Money& left, const Money& right);
	friend std::ostream& operator<< (std::ostream& out, const Money& point);

private:
	int rub;
	char kopek;
};

