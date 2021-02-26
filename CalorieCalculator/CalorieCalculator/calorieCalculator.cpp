#include <iostream>
#include <string>
using namespace std;
int main()
{

	double Weight;
	double Height;
	double ActivityFactor;
	double BMR;
	double CaloriesBurnt;

	int Age;

	cout << "Please input your weight (lb): ";
	cin >> Weight;

	cout << "Please input your height (ft): ";
	cin >> Height;

	cout << "Please input your age on your last birthday: ";
	cin >> Age;

	cout << "The following numbers represent various lifestyles, please enter only one.\n";
	cout << "1.2 (No exercise and desk job)\n";
	cout << "1.375 (Light exercise 1-3 times a week)\n";
	cout << "1.55 (Moderately active, exercise 3-5 times a week)\n";
	cout << "1.725 (Very active, exercise 6-7 times a week)\n";
	cout << "1.9 (Extra active, exercise two times a day. Includes marathons, etc.)\n";
	cin >> ActivityFactor;

	BMR = 66 + 6.2 * Weight + 152.4 * Height - 6.8 * Age;
	CaloriesBurnt = BMR * ActivityFactor;

	cout << "The calculation shows that you burn " << CaloriesBurnt <<" calories every day.\n";
	cout << "If your calorie intake is more than this, you may want to exercise more or reduce caloric intake.";

}	