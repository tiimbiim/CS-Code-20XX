/*
Student Name: Timothy Vu
ID Number: 2543344
Operating System Used: Windows
Compiler Used: Visual Studio
Date and Time Last Compiled: Dec 6, 2020
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Global Constant
const double CREDIT_LIMIT = 1500.00;
// Struct
struct CreditCard
{
	string FirstName;
	string LastName;
	string CCN;
	double balance;
};

void ChargeToCard(CreditCard& CC, double money);
void print(const CreditCard & CC);
void bubbleSort(CreditCard ccArr[], int flag, int len);
int LinearSearch(const CreditCard ccArr[], const CreditCard & CC, int flag, int len);
void print(const CreditCard arr[], int len);
void makePaymentToCard(CreditCard & CC, double money);
//Array Capacity
const int MAX = 100;

int main()
{

	CreditCard CC1 = { "JIM", "JONES", "56738", 0.0 };
	ChargeToCard(CC1, 200.99);
	CreditCard CC2 = { "ADAM", "ASHLEY", "12345", 0.0 };
	ChargeToCard(CC2, 2000.00);
	CreditCard CC3 = { "BERTHA", "MAPOS", "34567", 0.0 };
	ChargeToCard(CC3, 800.91);
	CreditCard CC4 = { "LISA", "BRAVE", "98765", 0.0 };
	ChargeToCard(CC4, 1001.23);
	CreditCard CC5 = { "WILLY", "NILLY", "23413", 0.0 };
	ChargeToCard(CC5, 700.00);
	CreditCard CC6 = { "JILL", "QUIRK", "67895", 0.0 };
	ChargeToCard(CC6, 1400.91);

	CreditCard CardArray[MAX];

	CardArray[0] = CC1;
	CardArray[1] = CC2;
	CardArray[2] = CC3;
	CardArray[3] = CC4;
	CardArray[4] = CC5;
	CardArray[5] = CC6;
	bool done = false;

	int arrLength = 6;
	int lnFlag = 1;
	int ccnFlag = 2;
	int balFlag = 3;

	while (!done) {
		cout << "Enter the menu item number below and then press enter key." << endl
			<< "1. Print credit card list in its current state.\n"
			<< "2. Sort based on last name.\n"
			<< "3. Sort based on credit card number\n"
			<< "4. Sort based on balance.\n"
			<< "5. Search based on last name.\n"
			<< "6. Search based on credit card number.\n"
			<< "7. Exit.\n";
		int choice;
		cin >> choice;

		if (choice == 7) {
			done = true;
		}
		else if (choice == 1) {

			print(CardArray, arrLength);

		}
		else if (choice == 2) {
			
			cout << "The array will be sorted by last name and printed below.\n";
			bubbleSort(CardArray, lnFlag, arrLength);

		}
		else if (choice == 3) {
			
			cout << "The array will be sorted by credit card number and printed below.\n";
			bubbleSort(CardArray, ccnFlag, arrLength);

		}
		else if (choice == 4) {

			cout << "The array will be sorted by balance and printed below.\n";
			bubbleSort(CardArray, balFlag, arrLength);

		}
		else if (choice == 5) {
		
			LinearSearch(CardArray, CC1, lnFlag, arrLength);

		}
		else if (choice == 6) {

			LinearSearch(CardArray, CC1, ccnFlag, arrLength);

		}
		else {

			cout << "This menu item has not yet been implemented.\n";

		}
	}
}

void print(const CreditCard& CC) {
	
	cout << "CNN: " << CC.CCN << "\n";
	cout << "Name: " << CC.FirstName;
	cout << " " << CC.LastName << "\n";
	cout << fixed << showpoint << setprecision(2) << "Amount owed: $" << CC.balance << "\n";
	cout << "--------------------------------------------------\n";

}

void print(const CreditCard arr[], int len) {

	for (int i = 0; i < len; i++) {

		print(arr[i]);

	}
}

int LinearSearch(const CreditCard ccArr[], const CreditCard& CC, int flag, int len) {

	string search;
	bool found = false;
	int index = 0;

	if (flag == 1) {

		cout << "\nPlease enter a last name in all capitals (e.g. Adams as ADAMS): \n";
		cin >> search;

		for (index; index < len && !found; index++) {

			if (ccArr[index].LastName == search) {
				found = true;

				cout << "Here's what we found:\n\n";

				print(ccArr[index]);
				return index;
			}

		}

		cout << "Our records do not contain anyone with the last name " << search << ".\n\n";
		return -1;

	}
	else if (flag == 2) {

		cout << "\nPlease enter a card number.\n";
		cin >> search;

		for (index; index < len && !found; index++) {

			if (ccArr[index].CCN == search) {
				found = true;

				cout << "Here's what we found:\n\n";

				print(ccArr[index]);
				return index;
			}

		}

		cout << "Our records do not contain a card number of " << search << ".\n\n";
		return -1;

	}

	return -1;

}

void bubbleSort(CreditCard ccArr[], int flag, int len) {

	string tempLN, tempFN, tempCN;
	double tempBL;

	if (flag == 1) {

		for (int passes = 0; passes < len; passes++) {

			for (int i = 0; i < len - passes - 1; i++) {

				if (ccArr[i].LastName > ccArr[i + 1].LastName) {

					tempLN = ccArr[i].LastName;
					tempFN = ccArr[i].FirstName;
					tempCN = ccArr[i].CCN;
					tempBL = ccArr[i].balance;
					ccArr[i].LastName = ccArr[i + 1].LastName;
					ccArr[i].FirstName = ccArr[i + 1].FirstName;
					ccArr[i].CCN = ccArr[i + 1].CCN;
					ccArr[i].balance = ccArr[i + 1].balance;
					ccArr[i + 1].LastName = tempLN;
					ccArr[i + 1].FirstName = tempFN;
					ccArr[i + 1].CCN = tempCN;
					ccArr[i + 1].balance = tempBL;

				}

			}

		}

	}

	if (flag == 2) {

		for (int passes = 0; passes < len; passes++) {

			for (int i = 0; i < len - passes - 1; i++) {

				if (ccArr[i].CCN > ccArr[i + 1].CCN) {

					tempCN = ccArr[i].CCN;
					tempLN = ccArr[i].LastName;
					tempFN = ccArr[i].FirstName;
					tempBL = ccArr[i].balance;
					ccArr[i].CCN = ccArr[i + 1].CCN;
					ccArr[i].LastName = ccArr[i + 1].LastName;
					ccArr[i].FirstName = ccArr[i + 1].FirstName;
					ccArr[i].balance = ccArr[i + 1].balance;
					ccArr[i + 1].CCN = tempCN;
					ccArr[i + 1].LastName = tempLN;
					ccArr[i + 1].FirstName = tempFN;
					ccArr[i + 1].balance = tempBL;

				}

			}

		}

	}

	if (flag == 3) {

		

		for (int passes = 0; passes < len; passes++) {

			for (int i = 0; i < len - passes - 1; i++) {

				if (ccArr[i].balance > ccArr[i + 1].balance) {

					tempBL = ccArr[i].balance;
					tempCN = ccArr[i].CCN;
					tempLN = ccArr[i].LastName;
					tempFN = ccArr[i].FirstName;
					ccArr[i].balance = ccArr[i + 1].balance;
					ccArr[i].CCN = ccArr[i + 1].CCN;
					ccArr[i].LastName = ccArr[i + 1].LastName;
					ccArr[i].FirstName = ccArr[i + 1].FirstName;
					ccArr[i + 1].balance = tempBL;
					ccArr[i + 1].CCN = tempCN;
					ccArr[i + 1].LastName = tempLN;
					ccArr[i + 1].FirstName = tempFN;

				}

			}

		}

	}

	for (int i = 0; i < len; i++) {

		print(ccArr[i]);

	}

}


void ChargeToCard(CreditCard& CC, double money) {
	
	if ((CC.balance + money) > CREDIT_LIMIT) {

		cout << fixed << showpoint << setprecision(2) 
			 << CC.FirstName << " " << CC.LastName << ": Charging $" << money << " will exceed the credit limit. "

			 << "The transaction has been declined.\n";
		cout << "--------------------------------------------------\n";

	}
	else {

		CC.balance += money;

	}

}

void makePaymentToCard(CreditCard& CC, double money) {

	CC.balance -= money;

	if (CC.balance < 0) {

		cout << "You paid more than you owed. The extra pay has been returned.";	
		CC.balance = 0;			//in case someone pays more than owed
		
	}

}
