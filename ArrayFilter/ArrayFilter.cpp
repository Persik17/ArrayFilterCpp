#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

// Predicate function: returns true if a number is odd
static bool isOdd(int num) {
	return (num % 2 != 0);
}

// Filter function: filters elements based on the predicate
static int filter(int* sourceArray, int size, bool (*predicate)(int), int* filteredArray) {
	int newSize = 0;
	for (int i = 0; i < size; ++i) {
		if (predicate(sourceArray[i])) {
			filteredArray[newSize] = sourceArray[i];
			newSize++;
		}
	}
	return newSize;
}

int main() {
	// Random number generation setup
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 100); // Range 1 to 100
	uniform_int_distribution<> sizeDistrib(5, 15);

	// Random size for array (between 5 and 15)
	int size = sizeDistrib(gen);

	// Allocate memory dynamically for sourceArray
	int* sourceArray = new int[size];

	// Fill sourceArray with random numbers
	for (int i = 0; i < size; ++i) {
		sourceArray[i] = distrib(gen);
	}

	int* filteredArray = new int[size]; // Allocate memory for the filtered array

	// Filter the array using the isOdd predicate
	int newSize = filter(sourceArray, size, isOdd, filteredArray);

	// Print the original and filtered arrays
	cout << "Original array: ";
	for (int i = 0; i < size; ++i) {
		cout << sourceArray[i] << " ";
	}
	cout << endl;

	cout << "Filtered array (odd numbers): ";
	for (int i = 0; i < newSize; ++i) {
		cout << filteredArray[i] << " ";
	}
	cout << endl;

	delete[] sourceArray;
	delete[] filteredArray;
	return 0;
}