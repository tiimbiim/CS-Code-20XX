#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {

	string nameF;
	string nameL;
	int id;
	char empCode;	//S, O, M
	int clCode;		//1, 2, 3
	int serviceYears;
	int edCode;		//1, 2, 3, 4

	string wholeName;
	bool empCodeFlag;
	bool clCodeFlag;
	bool serviceYearsFlag;
	bool edCodeFlag;
	double basePay;
	double totalPennies;
	int roundedPennies;
	double edCodeIncr = 0;		//initially set to 0 to prevent uninitialized error if edCode is 1
	double serviceYearsIncr;
	double clCodeIncr;

	double rawPay;		//Made changes to remove dollars and cents variables, rawPay is now the output variable

	cout << "Welcome to the Gross Salary Computer.\n";
	cout << "Please enter your first name: ";
	cin >> nameF;

	cout << "Please enter your last name: ";
	cin >> nameL;

	cout << "Please enter your employee code (Valid values are S, O, or M): ";
	cin >> empCode;

	cout << "Please enter your ID number: ";
	cin >> id;

	cout << "Please enter your job classification (Valid values are 1, 2, 3): ";
	cin >> clCode;

	cout << "Please enter the amount of years you have worked here (Anything over 50 is invalid): ";
	cin >> serviceYears;

	cout << "Please enter your educational code (Valid values are 1, 2, 3, 4): ";
	cin >> edCode;

	empCodeFlag = (empCode == 'S') || (empCode == 'O') || (empCode == 'M');
	clCodeFlag = (clCode == 1) || clCode == 2 || clCode == 3;
	edCodeFlag = (edCode == 1) || edCode == 2 || edCode == 3 || edCode == 4;
	serviceYearsFlag = serviceYears >= 0 && serviceYears <= 50;

	if (empCodeFlag && clCodeFlag && edCodeFlag && serviceYearsFlag) {

		cout << left << setw(20) << "\nName" << setw(20) << "ID Number" << setw(20) << "Job Type" << "Gross Salary ($)\n";

		wholeName = nameF + " " + nameL;

		if (empCode == 'S')
			basePay = 800.95;
		else if (empCode == 'O')
			basePay = 1000.86;
		else
			basePay = 1499.89;


		if (clCode == 1)
			clCodeIncr = basePay * (0.05);
		else if (clCode == 2)
			clCodeIncr = basePay * (0.1);
		else
			clCodeIncr = basePay * (0.2); 


		if (edCode == 2)
			edCodeIncr = basePay * (0.05);
		else if (edCode == 3)
			edCodeIncr = basePay * (0.12);
		else if (edCode == 4)
			edCodeIncr = basePay * (0.2);


		if (serviceYears <= 10)
			serviceYearsIncr = basePay * (0.05);
		else
			serviceYearsIncr = basePay * ((0.05 + (abs(10-serviceYears)/100.0)));

		rawPay = basePay + clCodeIncr + edCodeIncr + serviceYearsIncr;

		cout << setw(19) << wholeName;
		cout << setw(20) << id;

		if (empCode == 'S')
			cout << setw(20) << "Factory Worker";
		else if (empCode == 'O')
			cout << setw(20) << "Office Worker";
		else
			cout << setw(20) << "Management";

		cout << "$" << fixed << showpoint << setprecision(2) << rawPay << "\n";

	}
	else {
		if (!empCodeFlag)
			cout << "The employee code you have entered is invalid.\n";
		if (!clCodeFlag)
			cout << "The job classification code you have entered is invalid.\n";
		if (!serviceYearsFlag)
			cout << "The amount of years you have entered is invalid.\n";
		if (!edCodeFlag)
			cout << "The educational code you have entered is invalid.\n";

		cout << "Please try again.";
	}
	


}