#include "TimeDate.h"

int main() {
	int h = 8;
	int m = 36;
	int s = 24;
	int dd = 17;
	int mm = 12;
	int gg = 2020;
	TimeDate rd1{ h, m, s, dd, mm, gg };
	TimeDate rd2{ 15, m, s, dd, mm, gg };

	rd1.print();
	std::cout << "\n";
	rd2.print();
}