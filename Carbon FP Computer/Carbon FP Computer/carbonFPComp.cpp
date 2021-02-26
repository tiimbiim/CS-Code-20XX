#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int main() {

	string fileName;
	ifstream inFile;
	ofstream outFile;

	cout << "Please enter the file path for input.\n";
	getline(cin, fileName);
	inFile.open(fileName);		//"C:\\Users\\timbi\\Desktop\\DataFilesForAssignment5\\CarbonFP.txt"

	if (inFile.is_open()) {

		if (inFile.peek() != EOF) {

			cout << "Please enter the file path for output.\n";
			getline(cin, fileName);
			outFile.open(fileName, ios::app);		//"C:\\Users\\timbi\\Desktop\\DataFilesForAssignment5\\CarbonFPOUTPUT.txt"

			if (outFile.is_open()) {

				cout << fixed << showpoint << setprecision(2);
				outFile << fixed << showpoint << setprecision(2);

				int cityCount = 0;
				double totalTax = 0.0;
				string cityName;
				int cityScore = 0;
				double sumCityScore;
				double valSum;
				double avgCityScore;
				int avgCityScoreRounded;
				double cityTax = 0.0;

				cout << left << setw(35) << "City Name" << setw(40) << "Rounded Avg Carbon FP" << "Fines ($)\n";
				outFile << left << setw(35) << "City Name" << setw(40) << "Rounded Avg Carbon FP" << "Fines ($)\n";
				cout << "***********************************************************************************************\n";
				outFile << "***********************************************************************************************\n";


				while (inFile.peek() != EOF) {

					cityCount++;
					inFile >> cityName;		//don't want to store to whole line, just to first whitespace
					inFile >> cityScore;
					sumCityScore = 0.0;		//need to reset both of these to 0 for each city
					valSum = 0.0;

					while (cityScore >= 0) {

						valSum++;
						sumCityScore += cityScore;
						inFile >> cityScore;
					}

					cout << setw(35) << cityName;
					outFile << setw(35) << cityName;

					avgCityScore = sumCityScore / valSum;
					avgCityScoreRounded = int(avgCityScore + 0.5);

					if (avgCityScoreRounded < 0) {
						cout << "No Carbon FP data available. ";
						outFile << "No Carbon FP data available. ";
					}
					else {

						cout << left << setw(40) << avgCityScoreRounded;
						outFile << left << setw(40) << avgCityScoreRounded;
					}


					if (avgCityScoreRounded > 0 && avgCityScoreRounded <= 1) {
						cityTax = 0.00;
						cout << left << setw(35) << cityTax << "\n";
						outFile << left << setw(35) << cityTax << "\n";
					}

					else if (avgCityScoreRounded > 1 && avgCityScoreRounded <= 3) {
						cityTax = 1000000.00;
						cout << left << setw(35) << cityTax << "\n";
						outFile << left << setw(35) << cityTax << "\n";
					}

					else if (avgCityScoreRounded > 3 && avgCityScoreRounded <= 5) {
						cityTax = 2000000.00;
						cout << left << setw(35) << cityTax << "\n";
						outFile << left << setw(35) << cityTax << "\n";
					}

					else if (avgCityScoreRounded > 5 && avgCityScoreRounded <= 7) {
						cityTax = 3000000.00;
						cout << left << setw(35) << cityTax << "\n";
						outFile << left << setw(35) << cityTax << "\n";
					}

					else if (avgCityScoreRounded > 7) {
						cityTax = 4500000.00;
						cout << left << setw(35) << cityTax << "\n";
						outFile << left << setw(35) << cityTax << "\n";
					}

					else {
						cout << "No fines have been added.\n";
						outFile << "No fines have been added.\n";
					}

					totalTax += cityTax;

				}

				cout << "The total fines accumulated are: $" << totalTax << "\n";
				outFile << "The total fines accumulated are: $" << totalTax << "\n";
				cout << "The total amount of cities reviewed are: " << cityCount;
				outFile << "The total amount of cities reviewed are: " << cityCount << "\n";
			}
			else {
				cout << "Failed to open output file, please try again.";
				outFile << "Failed to open output file, please try again.\n";
			}
		}
		else {
			cout << "This file is empty, please choose another.";
			outFile << "This file is empty, please choose another.\n";
		}
	}
	else {
		cout << "This input file path is invalid, please try again.";
		outFile << "This input file path is invalid, please try again.\n";
	}
}


