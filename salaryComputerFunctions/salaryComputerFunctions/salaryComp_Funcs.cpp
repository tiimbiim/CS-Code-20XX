/*
 Author: Tim Vu 
 Created: 10/27/2020
 Salary Calculator with Functions
*/

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

const double tax = 0.071;		//decimalized form of 7.1%

void greeting();
double getUserData(double& payRate, string& firstName, string& lastName, bool& healthPlan);
double getGrossSalary(double hoursWorked, double payRate);
double getTaxWitheld(double grossSalary);
double getNetSalary(double grossSalary, double taxWitheld, bool HealthPlan, string& HealthPlanStatusMessage);
void printResults(const string& firstName, const string& lastName, double hoursWorked, double payRate, double grossSalary, double taxWitheld, double netSalary, const string& HealthPlanStatus);
void goodbye();

int main() {

	double hW, pR, gS, nS, tW;
	string fN, lN, hPSM;
	bool hP;

	greeting();
	hW = getUserData(pR, fN, lN, hP);
	gS = getGrossSalary(hW, pR);
	tW = getTaxWitheld(gS);
	nS = getNetSalary(gS, tW, hP, hPSM);
	printResults(fN, lN, hW, pR, gS, tW, nS, hPSM);
	
	goodbye();

}

void greeting() {

	cout << "Welcome to the net salary computer. This program will calculate your pay check."
		 << "\nThis program will require your hourly pay rate, your hours worked, and your decision on a health plan."
		 << "\nThe entire process should take about 2 minutes.\n";

}

double getUserData(double& payRate, string& firstName, string& lastName, bool& healthPlan) {

	double hoursWorked;
	cout << "Please enter your first name: ";
	cin >> firstName;
	
	cout << "Please enter your last name: ";
	cin >> lastName;

	cout << "Please enter your hours worked (positive numbers only): ";
	cin >> hoursWorked;

	cout << "Please enter your hourly pay rate (if it is something like $8 and 96 cents, enter 8.96): ";
	cin >> payRate;

	cout << "Please enter 1 if you wish to purchase a health plan, or 0 to decline: ";
	cin >> healthPlan;

	return hoursWorked;
}

double getGrossSalary(double hoursWorked, double payRate) {

	double grossSalary;

	if (hoursWorked <= 40)
		grossSalary = hoursWorked * payRate;

	else
		grossSalary = (40 * payRate) + ((hoursWorked - 40) * (payRate * 1.5));

	return grossSalary;

}

double getTaxWitheld(double grossSalary) {

	double taxWitheld;

	taxWitheld = grossSalary * tax;

	return taxWitheld;

}

double getNetSalary(double grossSalary, double taxWitheld, bool HealthPlan, string& HealthPlanStatusMessage) {

	double netSalary;
	netSalary = grossSalary - taxWitheld;

	if (HealthPlan == 1) {

		if (netSalary >= 200) {

			HealthPlanStatusMessage = "You have been accepted for a health plan.";
			netSalary = netSalary - 200;
		}

		else
			HealthPlanStatusMessage = "You are not eligible for a health plan due to insufficient salary.";
	}
	else
		HealthPlanStatusMessage = "You have not opted in for a health plan.";

	if (netSalary > 0)		//check to make sure salary is not negative when being returned, should not be tripped though
		return netSalary;
}

void printResults(const string& firstName, const string& lastName, double hoursWorked, double payRate, double grossSalary, double taxWitheld, double netSalary, const string& HealthPlanStatus) {

	cout << "--------------------------------------------------------------------------------------------------------------\n";
	
	cout << "Here are your details: \n";
	cout << "Name: " << firstName << " " << lastName << "\n";
	cout << fixed << showpoint << setprecision(2) << "Hours worked: " << hoursWorked << " hours" << "\n";
	cout << fixed << showpoint << setprecision(2) << "Hourly pay rate: $" << payRate << "\n";
	cout << fixed << showpoint << setprecision(2) << "Gross salary: $" << grossSalary << "\n";
	cout << fixed << showpoint << setprecision(2) << "Tax witheld: $" << taxWitheld << "\n";
	cout << HealthPlanStatus;
	cout << fixed << showpoint << setprecision(2) << "\nYour net salary: $" << netSalary << "\n";

}

void goodbye() {

	cout << "--------------------------------------------------------------------------------------------------------------\n";
	cout << "Thank you for using the program. Have a wonderful day.\n";

}