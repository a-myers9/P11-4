// CardCheck.cpp - Anna Myers - November 8, 2026
// Description: Part 1: Checks an 8 digit credit card number, read in as an integer

#include <iostream>
using namespace std;

// Function prototype
bool isCardValid(int digits[], int size);

int main(void) {
	const int SIZE = 8;
	int number;

	cout << "Enter 8-digit credit card # or Q to quit: ";
	// Typing Q makes int read fail
	while (cin >> number) {
		int digits[SIZE];
		// remove digits from the right
		for (int i = SIZE - 1; i >= 0; i--) {
			digits[i] = number % 10;
			number /= 10;
		}

		if (isCardValid(digits, SIZE)) {
			cout << "Card is valid." << endl;
		}
		else {
			cout << "Card is not valid." << endl;
		}
		cout << "Enter 8-digit credit card # or Q to quit: ";

	}
	return 0;
}

// Digits [size - 1] is rightnost digit
// Rightmost digit and every other digit are added as is and remaining digits are doubled
// Card is valid if total ends in 0
bool isCardValid(int digits[], int size) {
	int total = 0;
	for (int i = size - 1; i >= 0; i--) {
		if ((size - 1 - i) % 2 == 0) {
			// Included digit is added as is
			total += digits[i];
		}
		else {
			// other digit are doubled
			int doubled = digits[i] * 2;
			if (doubled > 9) {
				doubled -= 9;
			}
			total += doubled;
		}
	}
	return total % 10 == 0;
}