// This program outputs the average monthly water bill 
// from the last four quarters
// GAVIN TORRECAMPO
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	float b1, b2, b3, b4;
	cout << "Please input your water bill for quarter 1:\n";
	cin >> b1;
	cout << "Please input your water bill for quarter 2:\n";
	cin >> b2;
	cout << "Please input your water bill for quarter 3:\n";
	cin >> b3;
	cout << "Please input your water bill for quarter 4:\n";
	cin >> b4;
	float monthly = (b1 + b2 + b3 + b4) / 12;
	cout << "Your average monthly bill is $" << setprecision(2) << fixed << monthly << ". ";
	if (monthly > 75)
		cout << "You are using escessive amounts of water.\n";
	else if (monthly >= 25)
		cout << "You are using a typical amount of water.\n";
	else 
		cout << "You are conserving water, impressive!\n";
}