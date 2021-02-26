#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main() {
	double a, b, c, d, e, f;

	double p1, p2, p3, p4;
	double rawCostCents;
	int totalCentsRounded;

	int dollars, cents;
	double totalSurfArea;

	cout << "Welcome to the tetrahedron painting cost computing program."
		 << "\nPlease enter six side lengths of a tetrahedron in the format [xx.xx] separated by spaces.\n";

	cin >> a >> b >> c
		>> d >> e >> f;

	p1 = (0.5) * (a + b + c);
	p2 = (0.5) * (c + d + e);
	p3 = (0.5) * (b + d + f);
	p4 = (0.5) * (a + e + f);

	totalSurfArea = sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - c)) + sqrt(p2 * (p2 - c) * (p2 - d) * (p2 - e))
				  + sqrt(p3 * (p3 - b) * (p3 - d) * (p3 - f)) + sqrt(p4 * (p4 - a) * (p4 - e) * (p4 - f));

	rawCostCents = totalSurfArea * 0.1;

	totalCentsRounded = int(rawCostCents + 0.5);
	dollars = totalCentsRounded / 100;
	cents = totalCentsRounded % 100;

	cout << fixed << showpoint << setprecision(5) << "\nThe total surface area is: " << totalSurfArea << " square inches.\n";
	cout << "The total cost to paint the tetrahedron is: $" << dollars << " and " << cents << " cents.\n";

	cout << "Thank you for using the tetrahedron painting cost computer. Goodbye.\n";






}