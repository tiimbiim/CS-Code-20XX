/*
* Author: Tim Vu
* Purpose: Subway sandwich shop
* Class: CSCI-1-1015
* 
*/
#include <iostream>
using namespace std;
int main() {

	const double salesTax = 0.101;

	string nameF, nameL;
	char sizeCode;
	int flourCode, fillingCode;

	double rawCost, baseCost, tax, flourCodeIncr, fillingCodeIncr, totalPennies;
	bool sizeCodeFlag, flourCodeFlag, fillingCodeFlag;
	int roundedPennies;

	int dollars, cents;

	cout << "Welcome to the subway sandwich shop.\n";
	cout << "Please enter your first and last name.\n";
	cin >> nameF >> nameL;

	cout << "\nHello, " << nameF << " " << nameL << ". ";

	cout << "Please select your desired sandwich size:\n";
	cout << "[S]ix inch, [T]welve inch, [E]ighteen inch, Two [F]eet\n";
	cin >> sizeCode;

	cout << "Please choose your desired flour:\n";
	cout << "Type 1 for white flour bread\n";
	cout << "Type 2 for organic wheat bread\n";
	cout << "Type 3 for multigrain bread\n";
	cout << "Type 4 for organic multigrain bread\n";
	cin >> flourCode;

	cout << "Please choose your desired filling:\n";
	cout << "Type 1 for cheese\n";
	cout << "Type 2 for artichokes\n";
	cout << "Type 3 for jalapenos\n";
	cout << "Type 4 for extra cheese\n";
	cout << "Type 5 for all offered fillings\n";
	cin >> fillingCode;

	sizeCodeFlag = sizeCode == 'S' || sizeCode == 'T' || 
				   sizeCode == 'E' || sizeCode == 'F';

	flourCodeFlag =	flourCode == 1 || flourCode == 2 || 
					flourCode == 3 || flourCode == 4;

	fillingCodeFlag = fillingCode == 1 || fillingCode == 2 || fillingCode == 3 ||
					  fillingCode == 4 || fillingCode == 5;

	if (sizeCodeFlag && flourCodeFlag && fillingCodeFlag) {

		if (sizeCode == 'S')
			baseCost = 1.03;

		else if (sizeCode == 'T')
			baseCost = 2.11;

		else if (sizeCode == 'E')
			baseCost = 3.39;

		else
			baseCost = 4.11;
		

		if (flourCode == 1)
			flourCodeIncr = 0;

		else if (flourCode == 2)
			flourCodeIncr = (0.1011 * baseCost);

		else if (flourCode == 3)
			flourCodeIncr = (0.1555 * baseCost);

		else
			flourCodeIncr = (0.2012 * baseCost);

		
		if (fillingCode == 1) {
			fillingCodeIncr = 0.0;
		}

		else if (fillingCode == 2) {
			fillingCodeIncr = 0.50 + (0.101 * baseCost);
		}

		else if (fillingCode == 3) {
			fillingCodeIncr = 0.25 + (0.155 * baseCost);
		}

		else if (fillingCode == 4) {
			fillingCodeIncr = 0.30 + (0.113 * baseCost);
		}

		else {
			fillingCodeIncr = 1.05 + (0.3695 * baseCost);
		}

		rawCost = baseCost + flourCodeIncr + fillingCodeIncr;
		tax = rawCost * salesTax;
		rawCost += tax;
		totalPennies = rawCost * 100;
		roundedPennies = int(totalPennies + 0.5);
		dollars = roundedPennies / 100;
		cents = roundedPennies % 100;

		cout << "\nYour sandwich will cost " << dollars << " dollars and " << cents << " cents.\n";
		cout << "Thank you for your purchase.";

	}
	else {

		cout << "\nWe could not go through with your purchase for the following reasons: \n";

		if (!sizeCodeFlag) {
			cout << "The size code you entered is invalid.\n";
		}

		if (!flourCodeFlag) {
			cout << "The flour code you entered is invalid.\n";
		}

		if (!fillingCodeFlag) {
			cout << "The filling code you entered is invalid.\n";
		}

	}
						

}