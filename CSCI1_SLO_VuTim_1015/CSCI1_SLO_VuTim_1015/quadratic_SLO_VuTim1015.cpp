#include <iostream>
#include <iomanip>
using namespace std;

double getRoots(int A1, int B1, int C1, double& root2);
void printRealSolutions(double root1, double root2);

int main() {

	int a, b, c;
	double root1, root2, discrim;
	bool done = false;

	cout << "Welcome to the quadratic formula computer. "
		 << "It will solve equations in the form of aX^2 + bX + c = 0 or aX^2 + c = 0.\n";

	cout << "a = 0 is not allowed, and imaginary solutions will not be computed. "
		 << "Please enter values for a, b, and c.\n";

	cout << scientific;

	while (!done) {

		cout << "a = ";
		cin >> a;


		if (a == 0) {

			done = true;

		}
		else {

			cout << "b = ";
			cin >> b;

			if (b == 0) {

				cout << "Your equation will have imaginary number roots.\n";
				cout << "At this time, the computer will not solve for imaginary solutions.\n";

			}
			else {

				cout << "c = ";
				cin >> c;


				while (c == 0) {

					cout << "c = 0 is not accepted at this time. Please choose a different value.\n";
					cout << "c = ";
					cin >> c;

				}


				discrim = b * b - 4.0 * a * c;


				if (discrim >= 0) {

					root1 = getRoots(a, b, c, root2);

					printRealSolutions(root1, root2);

				}
				else {

					cout << "At this time, the computer will not solve for imaginary solutions.\n";

				}
				
			}

		}	
	}
	cout << "a has been detected as 0. The program will now end.\n";
}

double getRoots(int A1, int B1, int C1, double& root2) {

	double root1 = (-B1 + sqrt((B1 * B1) - 4 * A1 * C1)) / (2.0 * A1);
	root2 = (-B1 - sqrt((B1 * B1) - 4 * A1 * C1)) / (2.0 * A1);
	
	return root1;

} 

void printRealSolutions(double root1, double root2) {

	if (root1 != root2) {
		cout << "Here are the two real solutions: \n";
		cout << setprecision(6) << "X1 = " << root1 << "\n";
		cout << setprecision(6) << "X2 = " << root2 << "\n";
	}
	else {

		cout << "Here is the one real solution: \n";
		cout << setprecision(6) << "X = " << root1 << "\n";

	}
}