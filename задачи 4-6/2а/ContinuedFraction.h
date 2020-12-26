#pragma once
#include <vector>
#include <ostream>
class ContinuedFraction {
public:
	ContinuedFraction(std::vector<double> arrIn, double xIn) {
		arr = arrIn;
		x = xIn;
		summ = calc();

	}

	void setArr(std::vector<double> arrIn) {
		arr = arrIn;
	}

	std::vector<double> getArr() {
		return arr;
	}

	double calc() {
		double sum = x / arr[arr.size() - 1];
		for (int i = arr.size() - 2; i > 0; i--) {
			sum = arr[i] + x / sum;
		}
		return sum;
	}

	friend std::ostream& operator<< (std::ostream& out, const ContinuedFraction& point);
	friend std::istream& operator>> (std::istream& in, ContinuedFraction& point);
private:
	std::vector<double> arr;
	double x;
	double summ;
};

