// CardCheck.cpp - Anna Myers - November 8, 2026
// Description: Part 1: Checks an 8 digit credit card number, read in as an integer.
// Part 2: checks a 16-digit credit card number read as a string.

#include <iostream>
using namespace std;

// Function prototype.
bool isCardValid(int digits[], int size);
bool isNumeric(string s);
bool isCorrectLength(string s);

int main(void) {
	const int SIZE = 16;
	string input;

	cout << "Enter 16-digit credit card # or Q to quit: ";
	cin >> input;
	while (input != "Q" && input != "q") {
		// Digits are check first
		if (!isNumeric(input)) {
			cout << "Error - card numbr must contain only digits." << endl;
		}
		else if (!isCorrectLength(input)) {
			cout << "Error - card number must contain 16 digits." << endl;
		}
		else {
			int digits[SIZE];
			for (int i = 0; i < SIZE; i++) {
				// convert char to its digit value
				digits[i] = input[i] - '0';
			}
			if (isCardValid(digits, SIZE)) {
				cout << "Card is valid." << endl;
			}
			else {
				cout << "Card is not valid." << endl;
			}
		}
		cout << endl;
		cout << "Enter 16-digit credit card # or Q to quit: ";
		cin >> input;
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

// Returns true if every character is 0 through 9
bool isNumeric(string s) {
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] < '0' || s[i] > '9') {
			return false;
		}
	}
	return true;
}

// Returns true if the string has exactly 16 char
bool isCorrectLength(string s) {
	return s.length() == 16;
}
