// *******************************************************************************
// Assignment 7A: File Head Program
// Author: Gavin Torrecampo
// Description: This program asks the user for the name of a file, displaying the 
// first 10 lines on screen. If file has fewer than 10 lines, the entire file
// will be displayed with a message indicating so.
// Status: Complete
// Date: April 2, 2024
// *******************************************************************************

#include<iostream>
#include<fstream>
#include <string>
using namespace std;

int main1() {
	ifstream file;
	string filename;
	cout << "\n* Enter name of file (available files: CountriesLong.txt, CountriesShort.txt) . . . ";
	cin >> filename;
	file.open(filename, ios::in);
	if (!file) {
		cout << "\n(!) File not found (!)\n";
		return 1;
	}
	string line;
	for (int i = 0; !file.eof() && i < 10; i++) {
		getline(file, line);
		cout << line << endl;
	}
	if (file.eof())
		cout << "\n* Displayed entire file *\n";
	file.close();
	return 0;
}