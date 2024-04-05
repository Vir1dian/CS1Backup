// *******************************************************************************
// Assignment 7B: File Display Program
// Author: Gavin Torrecampo
// Description: This program asks the user for the name of a file, displaying the 
// contents of the file on the screen. If file has over 24 lines, then it will 
// display 24 lines of output at a time, pausing for the user to strike a key 
// before the next 24 lines are displayed.
// Status: Complete
// Date: April 2, 2024
// *******************************************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main2() {
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
	int i = 0;
	while (!file.eof()) {
		string x;
		i++;
		if (i == 24) {
			cout << "\n\nPress ENTER to continue . . . \n\n";
			cin.get();
			i = 0;
		}
		getline(file, line);
		cout << line << endl;
	}
	if (file.eof())
		cout << "\n* Displayed entire file *\n";
	file.close();
	return 0;
}