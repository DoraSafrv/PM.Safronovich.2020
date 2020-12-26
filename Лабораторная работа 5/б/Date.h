#include <iostream>
class Date
{
public:
	Date(int hh, int mm, int ss) {
		this->dd = hh;
		this->mm = mm;
		this->gg = ss;

	}
	void setDD(int hh) {
		this->dd = hh;
	}
	void setMM(int mm) {
		this->mm = mm;
	}
	void setGG(int ss) {
		this->gg = ss;
	}

	int getDD() {
		return dd;
	}
	int getMM() {
		return mm;
	}
	int getGG() {
		return gg;
	}

	void printD();


	int dd;
	int mm;
	int gg;
};
