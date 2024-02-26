// *******************************************************************************
// Assignment 2B: Stadium Seating
// Author: Gavin Torrecampo
// Description: Calculates ticket sales based on number of tickets sold for each
// seating class (A: $15, B: $12, C: $9)
// Status: Complete
// Date: January 31, 2024
// ********************************************************************************
#include<iostream>
#include<iomanip>
using namespace std;

int main2() {
	double a, b, c;
	cout << "Enter number of Class A tickets sold: " << endl;
	cin >> a;
	cout << "Enter number of Class B tickets sold: " << endl;
	cin >> b;
	cout << "Enter number of Class C tickets sold: " << endl;
	cin >> c;
	cout << "Ticket sales: " << setprecision(2) << fixed << (a * 15 + b * 12 + c * 9);
	return 0;
}