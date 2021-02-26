#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std; 
int main()
{
	double a;
	double b;
	double c;

	double x;
	double discriminant;
	double rootValue;

	cout << scientific;

	cout << "Hello, welcome to the quadratic formula solver. This program only works if a, b, and c are integers, and a is not zero.\n";
	cout << "Please enter a value for a: ";
	cin >> a;
	if (a == 0) {
		cout << "You have inputted a as 0. This will create a linear equation. Please continue if you wish to solve bx+c=0.\n";
	}

	cout << "Please enter a value for b: ";
	cin >> b;
	if (a == 0 && b == 0) {
		cout << "Variables a and b have been entered as 0. This results in a non algebraic equation. ";
	}

	if (a != 0 || b != 0) {
		cout << "Please enter a value for c: ";
		cin >> c;
	}

	if (a != 0) {
		discriminant = (b * b) - (4 * a * c);

		if (discriminant > 0) {
			x = (-b + sqrt((b * b) - 4 * a * c)) / (2 * a);
			cout << setprecision(4) << "There are two real solutions: X = " << x;
			x = (-b - sqrt((b * b) - 4 * a * c)) / (2 * a);
			cout << setprecision(4) << " and X = " << x;
		}
		else if (discriminant < 0) {
			if (b == 0) {
				rootValue = sqrt(abs((b * b) - (4 * a * c))) / (2 * a);
				cout << "There are two imaginary solutions: X = (" << rootValue << ")*I";
				rootValue = -sqrt(abs((b * b) - (4 * a * c))) / (2 * a);
				cout << setprecision(5) << " and X = (" << rootValue << ")*I";
			}
			else {
				x = double(-b) / (2 * double(a));
				rootValue = sqrt(abs((b * b) - (4 * a * c))) / (2 * a);
				cout << setprecision(4) << "There are two imaginary solutions: X = " << x << " + (" << rootValue << ")*I";
				x = double(-b) / (2 * double(a));
				rootValue = sqrt(abs((b * b) - (4 * a * c))) / (2 * a);
				cout << setprecision(4) << " and X = " << x << " - (" << rootValue << ")*I";
			}
		}
		else {
			x = (-b + sqrt((b * b) - 4 * a * c)) / (2 * a);
			cout << setprecision(4) << "There is only one real solution: X = " << x;
		}
	}
	else
		if (a == 0 && b == 0) {
			cout << "Please try again with valid numbers.";
		}
		else {
			x = double(-c) / double(b);
			cout << setprecision(4) << "The solution is: X = " << x;
		}
}