#include <iostream>
#include "Array.h"

void SelectionSort(MyArray<int> A, int n)
{
	int count, key;
	for (int i = 0; i < n - 1; i++)
	{
		count = A[i]; key = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[key]) key = j;
		if (key != i)
		{
			A[i] = A[key];
			A[key] = count;
		}
	}
}

void BubbleSort(MyArray<int> A, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (A[j - 1] > A[j])
			{
				int temp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = temp;
			}
		}
	}
}

int main() {
	std::cout << "Number of elements?\n";
	int numOfElements;
	std::cin >> numOfElements;

	std::cout << "Type of elements?\n";
	std::cout << "0 - int\n";
	std::cout << "1 - double\n";
	int switcher;
	std::cin >> switcher;
	switch (switcher) {
	case 0: {
		MyArray<int> ar = MyArray<int>(numOfElements);
		std::cout << "Input elements:\n";
		break;
	}
	case 1: {
		MyArray<double> ar = MyArray<double>(numOfElements);
		std::cout << "Input elements:\n";
		break;
	}
	default:
		MyArray<int> ar = MyArray<int>(numOfElements);
		std::cout << "default - int\n";
		break;
	}
	MyArray<int> ar = MyArray<int>(numOfElements);
	for (int i = 0; i < ar.getLength(); i++) {
		std::cin >> ar[i];
	}

	std::cout << "0 - bubble sort\n";
	std::cout << "1 - selection sort\n";
	int switcher2;
	std::cin >> switcher2;
	switch (switcher2) {
	case 0: {
		BubbleSort(ar, ar.getLength());
		break;
	}
	case 1: {
		SelectionSort(ar, ar.getLength());
		break;
	}
	default:
		BubbleSort(ar, ar.getLength());
		std::cout << "default - bubble sort\n";
		break;
	}
	for (int i = 0; i < ar.getLength(); i++) {
		std::cout << ar[i] << " ";
	}
}