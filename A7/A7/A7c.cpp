// *******************************************************************************
// Assignment 7C: File Display Program (Modified)
// Author: Gavin Torrecampo
// Description: Similar to 7B, but includes line numbering
// Status: Complete
// Date: April 2, 2024
// *******************************************************************************

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main3() {
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
		if (i != 0 && i % 24 == 0) {
			cout << "\n\nPress ENTER to continue . . . \n\n";
			cin.get();
		}
		getline(file, line);
		cout << i << ":" << line << endl;
	}
	if (file.eof())
		cout << "\n* Displayed entire file *\n";
	file.close();
	return 0;
}