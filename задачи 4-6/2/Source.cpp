#include "Money.h"
#include <iostream>
int main() {
	Money m1{ 12, '5' };
	std::cout << "m1 = " << m1 << "\n";
	Money m2{ 10, '9' };
	std::cout << "m2 = " << m2 << "\n";
	std::cout << "m1 + m2 = " << m1 + m2 << "\n";
	std::cout << "m1 - m2 = " << m1 - m2 << "\n";
	std::cout << "m1 > m2 ? " << (m1 > m2) << "\n";
	std::cout << "m1 < m2 ? " << (m1 < m2) << "\n";
	std::cout << (m2 < m1);
}