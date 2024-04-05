// *******************************************************************************
// Assignment 6B: Rainfall Statistics
// Author: Gavin Torrecampo
// Description: This program lets the user enter the total rainfall for each of 
// 12 months into an array of doubles and calculates and displays the following:
// total rainfall for the year, average monthly rainfall, and months with the 
// highest and lowest amounts.
// Status: Complete
// Date: March 22, 2024
// *******************************************************************************

#include<iostream>
using namespace std;

int main2() {
	const int SIZE = 12;
	double rain, max, min, total = 0;
	string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	string max_month, min_month;
	double rainfalls[SIZE];
	for (int i = 0; i < SIZE; i++) {
		cout << "\nEnter amount of rainfall for month " << months[i] << " . . . ";
		cin >> rain;
		while (rain < 0) {
			cout << "\nAmount cannot be negative, try again . . . ";
			cin >> rain;
		}

		rainfalls[i] = rain;
		total += rain;
		if (i == 0)
			max = rain, min = rain;
		if (rain >= max) {
			max = rain;
			max_month = months[i];
		}
		if (rain <= min) {
			min = rain;
			min_month = months[i];
		}
	}
	cout << "\nTotal rainfall for the year: " << total;
	cout << "\nAverage monthly rainfall: " << total / SIZE;
	cout << "\nMonth with highest rainfall: " << max_month << " at " << max;
	cout << "\nMonth with highest rainfall: " << min_month << " at " << min;
	return 0;
}