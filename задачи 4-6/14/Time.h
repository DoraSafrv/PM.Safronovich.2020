#pragma once
#include <iostream>
class Time {
public:
	Time(int hh, int mm, int ss) {
		this->h = hh;
		this->m = mm;
		this->s = ss;

	}
	void setH(int hh) {
		this->h = hh;
	}
	void setM(int mm) {
		this->m = mm;
	}
	void setS(int ss) {
		this->s = ss;
	}

	int getH() {
		return h;
	}
	int getM() {
		return m;
	}
	int getS() {
		return s;
	}

	void printT();

	int h;
	int m;
	int s;
};
