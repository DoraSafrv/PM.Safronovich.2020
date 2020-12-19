#include "TimeDate.h"

int main() {
	int h = 8;
	int m = 36;
	int s = 24;
	int dd = 17;
	int mm = 12;
	int gg = 2020;
	TimeDate rd{ h, m, s, dd, mm, gg };
	rd.print();
}