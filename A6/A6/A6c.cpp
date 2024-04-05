// *******************************************************************************
// Assignment 6C: Chips and Salsa
// Author: Gavin Torrecampo
// Description: This program lets a maker of chips and salsa keep track of sales 
// for five different types of salsa: mild, medium, sweet, hot and zesty.
// Status: Complete
// Date: March 22, 2024
// *******************************************************************************

#include<iostream>
#include<string>
using namespace std;

/**
 * This function reformats a string to align it to the left of a given space
 * @param string: String to be aligned, length must be less than or equal to 
 * provided space
 * @param int: Space provided as a count of whitespaces
 */
string align_l(string, int);

int main() {
	const int SIZE = 5;
	string salsas[] = { "mild", "medium", "sweet", "hot", "zesty" };
	int sales[SIZE];
	int num, min, max, total = 0;
	string min_salsa, max_salsa;
	for (int i = 0; i < SIZE; i++) {
		cout << "Enter number of jars sold for salsa type (" << salsas[i] << ") . . . ";
		cin >> num;
		while (num < 0) {
			cout << "\nAmount cannot be negative, try again . . . ";
			cin >> num;
		}

		sales[i] = num;
		total += num;
		if (i == 0)
			max = num, min = num;
		if (num >= max) {
			max = num;
			max_salsa = salsas[i];
		}
		if (num <= min) {
			min = num;
			min_salsa = salsas[i];
		}
	}
	string table_headers = "| ", table_values = "| ";
	for (int i = 0; i < SIZE; i++) {
		table_headers += align_l(salsas[i], 8) + " | ";
		table_values += align_l(to_string(sales[i]), 8) + " | ";
	}
	cout << "\nSales report";
	cout << endl << table_headers << endl << table_values;
	cout << "\nTotal sales: " << total;
	cout << "\nHighest selling product: " << max_salsa << " at " << max;
	cout << "\nLowest selling product: " << min_salsa << " at " << min << endl;
	return 0;
}

string align_l(string item, int space) {
	string new_string = item;
	for (int i = 0; i < space - item.length(); i++)
		new_string += " ";
	return new_string;
}