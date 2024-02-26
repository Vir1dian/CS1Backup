// *******************************************************************************
// Assignment 2A: Miles per Gallon
// Author: Gavin Torrecampo
// Description: This program prompts the user to enter max gallons a car can hold
// and the number of miles that can be driven by a full tank. Calculates and
// displays mileage.
// Status: Complete
// Date: January 31, 2024
// ********************************************************************************
#include<iostream>
using namespace std;

int main1() {
	double capacity, distance;
	cout << "Enter car's max fuel capacity (in gallons): " << endl;
	cin >> capacity;
	cout << "Enter car's max distance (in miles) with a full tank: " << endl;
	cin >> distance;
	cout << "Your car's mileage (miles per gallon): " << distance / capacity;
	return 0;
}