#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

const int MAX = 50;

struct CarType {

	double price;
	string customer;
	int arr[10] = { 1,2,3 };

	struct Plane {

		int name;
		double id;

	};


};

void GetCar(ifstream& in, CarType& cr);
void WriteCar(ofstream& out, const CarType& cr);
void printArray(int arr);
void fooBar(int& bar);
void calculateCost(int count, float& subtotal, float& taxCost);
void fooo(int bar);
int numChars(string name);
void getChoice(int& par_choice, int par_count);
void Mystery(int& P);
int f1(int x, int y);
int f2(float a, float b);
int myFunc(int myVal);
int func(double y);

struct GradStudent {

	string name;
	double GPA;


};
struct Foo {
	string phrase;
};


int main()
{
	//cout << boolalpha;


	int age;
	cin >> age;

	cout << age;

	//ifstream = inFile;

/*
* 
	cout << fixed << showpoint << setprecision(2);
	CarType car;
	ifstream dataIn;
	ofstream dataOut;
	dataIn.open("C:\\Users\\timbi\\Desktop\\tmbm\\school\\Elco\\CS1\\cars.txt");
	dataOut.open("C:\\Users\\timbi\\Desktop\\tmbm\\school\\Elco\\CS1\\carsOut.txt");
	dataOut << fixed << showpoint << setprecision(2);

	while (dataIn.peek() != EOF) {

		GetCar(dataIn, car);
		car.price = car.price * 1.10;
		WriteCar(dataOut, car);

	}

	

*/

	//inFile.open("C:\\Users\\timbi\\Desktop\\tmbm\\school\\Elco\\CS1\\DataFilesForAssignment5\\CarbonFP.txt");		//"C:\\Users\\timbi\\Desktop\\DataFilesForAssignment5\\CarbonFP.txt"

	/*float tax = 0.0;
	float subtotal = 0.0;

	calculateCost(15, subtotal, tax);

	cout << fixed << showpoint << setprecision(2);

	cout << "The cost for 15 items is " << subtotal << ", and the tax for " << subtotal << " is " << tax << endl; */

	//fooo(5);


	//int x = 8;

	//cout << fixed << setprecision(2);

	int arr[5] = { 1,2,3,4 };
	int arr2[5] = { 0, 2, 3, 5 };

	//Mystery(arr[7]);
	//Mystery(x);

}

int myFunc(int myVal) {

	myVal += 1;

	return myVal;

}

int f1(int x, int y) {

	x = y * y;

	return x;

}

void Mystery(int& P) {

	cout << P << endl;

}

void getChoice(int& par_choice, int par_count) {

	if (par_count < 0)
		par_choice = 0;

	if (par_count == 0)
		par_choice = -1;
	else
		par_choice = 99;

}

void GetCar(ifstream & in, CarType & cr) {

	in >> cr.customer >> cr.price;

}

void WriteCar(ofstream& out, const CarType& cr) {

	out << "Customer: " << cr.customer << endl
		<< "Price: $:" << cr.price << endl;

}

/*void printArray(int arr) {

	for (int i = 0; i < 2; i++) {

		for (int c = 0; c < 2; c++) {

			cout << arr[i][c];

		}

	}

} */

void calculateCost(int count, float& subtotal, float& taxCost) {

	if (count < 10) {

		subtotal = count * 0.50;

	}
	else {

		subtotal = count * 0.20;

	}

	taxCost = 0.1 * subtotal;

}

void fooBar(int& bar) {

	bar += 2;
	cout << "function has completed";

}